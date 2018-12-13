//
// Created by noam on 12/13/18.
//

#include "Div.h"

double Div::calculate() {
    return (this->left)->calculate() / (this->right)->calculate();
}