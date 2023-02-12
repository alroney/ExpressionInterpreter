#include "expression.h"

class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* left, Expression* right);
    virtual ~BinaryExpression();
    virtual double calculate() = 0;
protected:
    Expression* left;
    Expression* right;
};