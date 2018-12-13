//
// Created by noam on 12/13/18.
//

#include "Minus.h"

double Minus::calculate() {
    int i = 0;
    int j = i;
    return (this->left)->calculate() - (this->right)->calculate();
}