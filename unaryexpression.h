

class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression* expr, bool isNeg);

    double evaluate();
private:
    Expression* expr;
    bool isNeg;
};