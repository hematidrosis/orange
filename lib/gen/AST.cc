/*
** Copyright 2014-2015 Robert Fratto. See the LICENSE.txt file at the top-level 
** directory of this distribution.
**
** Licensed under the MIT license <http://opensource.org/licenses/MIT>. This file 
** may not be copied, modified, or distributed except according to those terms.
*/ 

#include "gen/AST.h"
#include "gen/generator.h"
#include "gen/Values.h"
#include "gen/ArgExpr.h"

ArgList* ArgList::clone() {
	ArgList *ret = new ArgList; 
	for (ArgExpr *expr : *this) {
		ret->push_back((ArgExpr *)expr->clone());
	}
	return ret;
}

Type *getType(std::string typeStr) {
	if (typeStr == "int" || typeStr == "int64") {
		return Type::getInt64Ty(getGlobalContext());
	} else if (typeStr == "int8" || typeStr == "char") {
		return Type::getInt8Ty(getGlobalContext());
	} else if (typeStr == "int16") {
		return Type::getInt16Ty(getGlobalContext());
	} else if (typeStr == "int32") {
		return Type::getInt32Ty(getGlobalContext());
	} else if (typeStr == "uint8" || typeStr == "int8") {
		return Type::getInt8Ty(getGlobalContext());
	} else if (typeStr == "uint16" || typeStr == "int16") {
		return Type::getInt16Ty(getGlobalContext());
	} else if (typeStr == "uint32" || typeStr == "int32") {
		return Type::getInt32Ty(getGlobalContext());
	} else if (typeStr == "uint" || typeStr == "uint64") {
		return Type::getInt64Ty(getGlobalContext());
	} else if (typeStr == "float") {
		return Type::getFloatTy(getGlobalContext());
	} else if (typeStr == "double") {
		return Type::getDoubleTy(getGlobalContext());
	} else if (typeStr == "void") {
		return Type::getVoidTy(getGlobalContext());
	} else {
		std::cerr << "FATAL: unknown type " << typeStr << "!\n";
	}

	return nullptr;
}