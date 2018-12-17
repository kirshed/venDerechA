//
// Created by daniella on 12/16/18.
//

#ifndef UNTITLED5_DIV_H
#define UNTITLED5_DIV_H


#include "BinaryExpression.h"

class Div: public BinaryExpression {
public:
    Div(Expression* le, Expression* re): BinaryExpression(le, re){}
    virtual double calculate() const;
};


#endif //UNTITLED5_DIV_H
