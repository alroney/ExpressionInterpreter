#include "expression.h"
#include "subexpression.h"

class Multiplication : public Expression {
public:
    Multiplication(Expression* left, Expression* right);
    double evaluate();
};