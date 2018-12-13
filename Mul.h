//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_MUL_H
#define INTERPRETERFLIGHT_MUL_H

#include "BinaryExpression.h"

class Mul : BinaryExpression {
public:
    Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    virtual double calculate();
};


#endif //INTERPRETERFLIGHT_MUL_H
