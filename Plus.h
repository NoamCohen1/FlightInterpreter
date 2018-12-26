#ifndef INTERPRETERFLIGHT_PLUS_H
#define INTERPRETERFLIGHT_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    virtual double calculate();
};

#endif //INTERPRETERFLIGHT_PLUS_H
