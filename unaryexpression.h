#include "expression.h"

class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression*);
    double evaluate();
private:
    Expression* expression;
};