//
// Created by daniella on 12/16/18.
//

#include "Div.h"

double Div::calculate() const{
    return this->left->calculate()/this->right->calculate();
}