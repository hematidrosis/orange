/*
** Copyright 2014-2015 Robert Fratto. See the LICENSE.txt file at the top-level 
** directory of this distribution.
**
** Licensed under the MIT license <http://opensource.org/licenses/MIT>. This file 
** may not be copied, modified, or distributed except according to those terms.
*/ 

#include <orange/types/VarTy.h>

VarTy* VarTy::get() {
	if (getDefined("var")) return (VarTy*)getDefined("var");
	return (VarTy*)define("var", new VarTy());
} 
