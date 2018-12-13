//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_PLUS_H
#define INTERPRETERFLIGHT_PLUS_H

#include "BinaryExpression.h"

class Plus : BinaryExpression {
public:
    Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    virtual double calculate();
};


#endif //INTERPRETERFLIGHT_PLUS_H
