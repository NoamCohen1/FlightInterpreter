//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_BINARYEXPRESSION_H
#define INTERPRETERFLIGHT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression *left, Expression *right) {
        this->left = left;
        this->right = right;
    }

    virtual double calculate() = 0;
};


#endif //INTERPRETERFLIGHT_BINARYEXPRESSION_H
