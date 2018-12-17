//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_DIV_H
#define INTERPRETERFLIGHT_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    virtual double calculate();
};


#endif //INTERPRETERFLIGHT_DIV_H
