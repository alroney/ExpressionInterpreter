

#include "expression.h"
#include "ternaryexpression.h"

TernaryExpression::TernaryExpression(Expression* condition, Expression* trueExpr, Expression* falseExpr) {
    this->condition = condition;
    this->trueExpr = trueExpr;
    this->falseExpr = falseExpr;
}

double TernaryExpression::evaluate() {//evaluate the condition and return the value of the expression trueExpr or falseExpr depending on the condition
    if (condition->evaluate() == 1) {//if the condition is true
        return trueExpr->evaluate();//return the value of the expression trueExpr
    } 
    else {
        return falseExpr->evaluate();//return the value of the expression falseExpr
    }
}