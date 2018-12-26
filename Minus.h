#ifndef INTERPRETERFLIGHT_MINUS_H
#define INTERPRETERFLIGHT_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    virtual double calculate();
};


#endif //INTERPRETERFLIGHT_MINUS_H
