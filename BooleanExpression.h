//
// Created by noam on 12/20/18.
//

#ifndef INTERPRETERFLIGHT_BOOLEANEXPRESSION_H
#define INTERPRETERFLIGHT_BOOLEANEXPRESSION_H

#include "Expression.h"

class BooleanExpression : public Expression {
protected:
    Expression *left;
    Expression *right;

public:
    BooleanExpression(Expression *left, Expression *right) {
        this->left = left;
        this->right = right;
    }

    virtual double calculate() = 0;
};


#endif //INTERPRETERFLIGHT_BOOLEANEXPRESSION_H
