//
// Created by daniella on 12/15/18.
//

#ifndef UNTITLED5_NUMBER_H
#define UNTITLED5_NUMBER_H


#include "Expression.h"

class Number: public Expression {
    double value;
public:
    Number(double val){
        value = val;
    }
    virtual double calculate() const;
};


#endif //UNTITLED5_NUMBER_H
