

#include "expression.h"
#include "unaryexpression.h"

UnaryExpression::UnaryExpression(Expression* expr, bool isNeg) {
    this->expr = expr;
    this->isNeg = isNeg;
}

double UnaryExpression::evaluate() {
    if (!isNeg) {
        return expr->evaluate();
    }
    
    return -1 * expr->evaluate();
}