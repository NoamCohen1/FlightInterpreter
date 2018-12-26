#include "Div.h"

double Div::calculate() {
    return (this->left)->calculate() / (this->right)->calculate();
}