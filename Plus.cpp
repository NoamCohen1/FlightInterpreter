//
// Created by noam on 12/13/18.
//

#include "Plus.h"

double Plus::calculate() {
    return (this->left)->calculate() + (this->right)->calculate();
}