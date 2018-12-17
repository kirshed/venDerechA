//
// Created by daniella on 12/15/18.
//

#ifndef UNTITLED5_BINARYEXPRESSION_H
#define UNTITLED5_BINARYEXPRESSION_H


#include "Expression.h"

class BinaryExpression: public Expression {
protected: Expression* left;
protected: Expression* right;
public:
    BinaryExpression(Expression* le, Expression* re){
        left = le;
        right = re;
    }
    virtual double calculate() const = 0;
};


#endif //UNTITLED5_BINARYEXPRESSION_H
