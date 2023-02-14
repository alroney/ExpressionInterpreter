

class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression* expr, bool isNeg) {
        this->expr = expr;
        this->isNeg = isNeg;
    }

    double evaluate() {
        if (!isNeg) {
            return expr->evaluate();
        }
        
        return -1 * expr->evaluate();
    }
private:
    Expression* expr;
    bool isNeg;
};