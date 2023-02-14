/*
* Name: Andrew Roney
* Date: 2/14/2023
* Project: Project 2
* Description: This file contains the implementation of the UnaryExpression class, which is a subclass of Expression. It contains
*   a constructor that takes two parameters: a pointer to an Expression object and a boolean value. It also
*   contains the body of the evaluate function, which returns the result of the operation on the subexpression.
*/

#include "expression.h"
#include "unaryexpression.h"

UnaryExpression::UnaryExpression(Expression* expr, bool isNeg) {
    this->expr = expr;
    this->isNeg = isNeg;
}

double UnaryExpression::evaluate() {//if the boolean value is false, return the result of the subexpression. If the boolean value is true, return the negative of the result of the subexpression
    if (!isNeg) {
        return expr->evaluate();
    }
    
    return -1 * expr->evaluate();
}