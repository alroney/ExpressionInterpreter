#include "expression.h"


class TernaryExpression : public Expression {
public:
    TernaryExpression(Expression* left, Expression* trueExpr, Expression* falseExpr);
    double evaluate();

private:
    Expression* left;
    Expression* trueExpr;
    Expression* falseExpr;
};