#include "Minus.h"

double Minus::calculate() {
    return (this->left)->calculate() - (this->right)->calculate();
}