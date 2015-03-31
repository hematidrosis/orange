/*
** Copyright 2014-2015 Robert Fratto. See the LICENSE.txt file at the top-level 
** directory of this distribution.
**
** Licensed under the MIT license <http://opensource.org/licenses/MIT>. This file 
** may not be copied, modified, or distributed except according to those terms.
*/ 

#ifndef __ORANGE_BLOCK_H__
#define __ORANGE_BLOCK_H__

#include "AST.h"
#include "SymTable.h"

class Block : public Statement {
private:
	/**
	 * The symbol table for this Block.
	 */
	SymTable *m_symtab;

	std::vector<ASTNode *> m_statements;
protected:
	/**
	 * Determines whether or not this block is locked,
	 * which will happen upon calling Codegen().
	 */
	bool m_locked = false;

	/**
	 * Generates all of the statements.
	 */
	void generateStatements();	
public:
	virtual std::string getClass() { return "Block"; }

	/**
	 * Adds a statement to the list of statements for this block.
	 * After Codegen has been called, no more statements can be 
	 * added and this function will do nothing.
	 *
	 * @param statement The statement to add to this block.
	 */
	void addStatement(ASTNode* statement); 

	/**
	 * Generates code for each statement added to this block.
	 * If a statement throws an exception during code generation,
	 * This will catch it and log it to the Runner.
	 *
	 * @return This function always returns nothing.
	 */ 
	Value* Codegen();

	virtual ASTNode* clone();

	virtual std::string string();

	/**
	 * This will resolve every statement added to this block.
	 */
	void resolve();

	/**
	 * Creates a block. Every block must have a symbol table attached to 
	 * it. A runtime_error will be thrown if symtab is nullptr.
	 *
	 * @param symtab The symtab for this block. Must not be null.
	 */
	Block(SymTable* symtab);
};

#endif 