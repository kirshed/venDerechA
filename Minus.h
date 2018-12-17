//
// Created by daniella on 12/15/18.
//

#ifndef UNTITLED5_MINUS_H
#define UNTITLED5_MINUS_H


#include "BinaryExpression.h"

class Minus: public BinaryExpression {
public:
    Minus(Expression* le, Expression* re): BinaryExpression(le, re){
    }
    virtual double calculate()const;
};


#endif //UNTITLED5_MINUS_H
