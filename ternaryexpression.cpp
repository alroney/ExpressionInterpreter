#include <iostream>

#include "ternaryexpression.h"

TernaryExpression::TernaryExpression(Expression* left, Expression* trueExpr, Expression* falseExpr) {
    this->left = left;
    this->trueExpr = trueExpr;
    this->falseExpr = falseExpr;
}

double TernaryExpression::evaluate() {
    return left->evaluate() ? trueExpr->evaluate() : falseExpr->evaluate();
}