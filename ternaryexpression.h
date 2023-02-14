

class TernaryExpression: public Expression {
public:
    TernaryExpression(Expression* condition, Expression* trueExpr, Expression* falseExpr) {
        this->condition = condition;
        this->trueExpr = trueExpr;
        this->falseExpr = falseExpr;
    }

    double evaluate() {//evaluate the condition and return the value of the expression trueExpr or falseExpr depending on the condition
        if (condition->evaluate() == 1) {//if the condition is true
            return trueExpr->evaluate();//return the value of the expression trueExpr
        } 
        else {
            return falseExpr->evaluate();//return the value of the expression falseExpr
        }
    }

private:

    Expression* condition;
    Expression* trueExpr;
    Expression* falseExpr;
};