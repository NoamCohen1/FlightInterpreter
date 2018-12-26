#include "Plus.h"

double Plus::calculate() {
    return (this->left)->calculate() + (this->right)->calculate();
}