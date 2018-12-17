//
// Created by daniella on 12/15/18.
//

#include "Plus.h"

double Plus::calculate() const {
    return this->left->calculate()+this->right->calculate();
}