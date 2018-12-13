//
// Created by noam on 12/13/18.
//

#include "Mul.h"

double Mul::calculate() {
    return (this->left)->calculate() * (this->right)->calculate();
}