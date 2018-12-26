#ifndef INTERPRETERFLIGHT_NUMBER_H
#define INTERPRETERFLIGHT_NUMBER_H

#include "Expression.h"

class Number : public Expression {
    double value;
public:
    Number(double num) {
        this->value = num;
    }

    double getValue() {
        return this->value;
    }

    virtual double calculate() {
        return this->value;
    }
};


#endif //INTERPRETERFLIGHT_NUMBER_H
