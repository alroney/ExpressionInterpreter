class Modulo: public SubExpression {
public:
    Modulo(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
       return fmod(left->evaluate(), right->evaluate());
    }
};