#include "expression.h"

class QuaternaryExpression : public Expression {
public:
    QuaternaryExpression(Expression* left, Expression* trueExpr, Expression* falseExpr, Expression* resultExpr);
    double evaluate();

private:
    Expression* left;
    Expression* trueExpr;
    Expression* falseExpr;
    Expression* resultExpr;
};