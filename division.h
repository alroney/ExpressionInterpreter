#include "expression.h"
#include "subexpression.h"

class Division : public SubExpression
{
public:
    Division(Expression* left, Expression* right) : SubExpression(left, right) {
    }
    double evaluate() {
        return left->evaluate() / right->evaluate();
    }
};