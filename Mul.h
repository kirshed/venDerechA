//
// Created by daniella on 12/16/18.
//

#ifndef UNTITLED5_MUL_H
#define UNTITLED5_MUL_H


#include "BinaryExpression.h"

class Mul: public BinaryExpression {
public:
    Mul(Expression* le, Expression* re): BinaryExpression(le, re){}
    virtual double calculate() const;
};


#endif //UNTITLED5_MUL_H
