//
// Created by noam on 12/13/18.
//

#include "Minus.h"

double Minus::calculate() {
    int k = 5;
    return (this->left)->calculate() - (this->right)->calculate();
}