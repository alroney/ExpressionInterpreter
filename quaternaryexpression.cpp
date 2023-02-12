#include "QuaternaryExpression.h"

QuaternaryExpression::QuaternaryExpression(Expression* left, Expression* trueExpr, Expression* falseExpr, Expression* resultExpr)
{
    this->left = left;
    this->trueExpr = trueExpr;
    this->falseExpr = falseExpr;
    this->resultExpr = resultExpr;
}

double QuaternaryExpression::evaluate()
{
    int leftValue = left->evaluate();
    if (leftValue < 0)
        return trueExpr->evaluate();
    else if (leftValue == 0)
        return falseExpr->evaluate();
    else
        return resultExpr->evaluate();
}
