/*
** Copyright 2014-2015 Robert Fratto. See the LICENSE.txt file at the top-level 
** directory of this distribution.
**
** Licensed under the MIT license <http://opensource.org/licenses/MIT>. This file 
** may not be copied, modified, or distributed except according to those terms.
*/ 

#include "gen/ReturnExpr.h"
#include "gen/generator.h"
#include "gen/VarExpr.h"
#include "gen/CastingEngine.h"

void ReturnExpr::resolve() {
	if (resolved)
		return;

	if (expr) {
		expr->resolve();
	}

	resolved = true;
}

Value* ReturnExpr::Codegen() {
	BasicBlock *bb = CG::Symtabs.top()->getFunctionEnd();
	if (bb == nullptr) {
		std::cerr << "fatal: no Function End found!\n";
		exit(1);
	}

	if (expr && CG::Symtabs.top()->getRetVal() == nullptr) {
		std::cerr << "fatal: no return value found (symtab " << CG::Symtabs.top()->ID << ") !\n"; 
		exit(1);
	}

	if (expr) {
		DEBUG_MSG("ReturnExpr: STARTING CODEGEN FOR EXPR");
		Value *v = expr->Codegen();

		if (expr->returnsPtr()) {
			v = CG::Builder.CreateLoad(v);
		}

		CastValueToType(&v, CG::Symtabs.top()->getRetVal()->getType()->getPointerElementType(), expr->isSigned(), true);

		CG::Builder.CreateStore(v, CG::Symtabs.top()->getRetVal());
		Value *r = CG::Builder.CreateBr(bb);
		return r; 
	} else {
		Value *r = CG::Builder.CreateBr(bb);
		return r;
	}
}

ReturnExpr::~ReturnExpr() {
	delete expr;
}