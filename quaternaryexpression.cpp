

#include "expression.h"
#include "quaternaryexpression.h"

QuaternaryExpression::QuaternaryExpression(Expression* condition, Expression* belowExpr, Expression* sameExpr, Expression* aboveExpr) {
    this->condition = condition;
    this->belowExpr = belowExpr;
    this->sameExpr = sameExpr;
    this->aboveExpr = aboveExpr;
}

double QuaternaryExpression::evaluate() {//evaluate the condition and return the value of the expression belowExpr, sameExpr, or aboveExpr depending on the condition
    if (condition->evaluate() < 0) {//if the condition is below 0
        return belowExpr->evaluate();//return the value of the expression belowExpr
    } 
    else if (condition->evaluate() == 0) {//if the condition is 0
        return sameExpr->evaluate();//return the value of the expression sameExpr
    }
    else {
        return aboveExpr->evaluate();//return the value of the expression aboveExpr
    }
}

