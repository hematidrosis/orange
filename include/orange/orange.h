/*
** Copyright 2014-2015 Robert Fratto. See the LICENSE.txt file at the top-level 
** directory of this distribution.
**
** Licensed under the MIT license <http://opensource.org/licenses/MIT>. This file 
** may not be copied, modified, or distributed except according to those terms.
*/ 

#include "AST.h"
#include "Values.h"
#include "Block.h"
#include "generator.h"
#include "VarExpr.h"
#include "BinOpExpr.h"
#include "ReturnStmt.h"
#include "FuncCall.h"
#include "NegativeExpr.h"
#include "ExternFunction.h"
#include "CondBlock.h"
#include "IfStmts.h"
#include "IncrementExpr.h"
#include "ExplicitDeclStmt.h"