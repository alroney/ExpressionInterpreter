#include "subexpression.h"

class Exponentiation : public SubExpression {
public:
    Exponentiation(Expression* left, Expression* right);
    double evaluate();
};