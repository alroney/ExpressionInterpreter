

class QuaternaryExpression : public Expression {
public:
    QuaternaryExpression(Expression* condition, Expression* below, Expression* same, Expression* above) {
        this->condition = condition;
        this->below = below;
        this->same = same;
        this->above = above;
    }

    double evaluate() {
        if (condition->evaluate() < 0) {
            return below->evaluate();
        }
        else if (condition->evaluate() == 0) {
            return same->evaluate();
        }
        else {
            return above->evaluate();
        }
    }
private:
    Expression* condition;
    Expression* below;
    Expression* same;
    Expression* above;
};