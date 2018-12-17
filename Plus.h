//
// Created by daniella on 12/15/18.
//

#ifndef UNTITLED5_PLUS_H
#define UNTITLED5_PLUS_H


#include "BinaryExpression.h"

class Plus: public BinaryExpression {
public:
    Plus(Expression* le, Expression* re): BinaryExpression(le, re){
        
    }
    virtual double calculate()const;
};


#endif //UNTITLED5_PLUS_H
