#include "expression.h"

class Negation : public Expression {
public:
    Negation(Expression*);
    double evaluate();
private:
    Expression* operand;
};