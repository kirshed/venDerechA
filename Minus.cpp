//
// Created by daniella on 12/15/18.
//

#include "Minus.h"

double Minus:: calculate()const{
    return this->left->calculate()-this->right->calculate();
}
