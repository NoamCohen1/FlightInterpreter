#include "Mul.h"

double Mul::calculate() {
    return (this->left)->calculate() * (this->right)->calculate();
}