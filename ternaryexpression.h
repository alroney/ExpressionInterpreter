

class TernaryExpression: public Expression {
public:
    TernaryExpression(Expression* condition, Expression* trueExpr, Expression* falseExpr);

    double evaluate();

private:

    Expression* condition;
    Expression* trueExpr;
    Expression* falseExpr;
};