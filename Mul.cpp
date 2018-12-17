//
// Created by daniella on 12/16/18.
//

#include "Mul.h"

double Mul::calculate() const {
    return this->left->calculate()*this->right->calculate();
}