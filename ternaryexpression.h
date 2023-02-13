

class TernaryExpression: public Expression {
public:
    TernaryExpression(Expression* condition, Expression* trueExpr, Expression* falseExpr) {
        this->condition = condition;
        this->trueExpr = trueExpr;
        this->falseExpr = falseExpr;
    }

    double evaluate() {
        if (condition->evaluate() == 1) {
            return trueExpr->evaluate();
        } 
        else {
            return falseExpr->evaluate();
        }
    }

private:

    Expression* condition;
    Expression* trueExpr;
    Expression* falseExpr;
};