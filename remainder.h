#include "subexpression.h"
#include "expression.h"

class Remainder : public SubExpression {
public:
    Remainder(Expression* left, Expression* right);
    double evaluate();
};