//
// Created by daniella on 12/16/18.
//

#ifndef UNTITLED5_SHUNTING_H
#define UNTITLED5_SHUNTING_H
#include <map>
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "Number.h"


using namespace std;

class Shunting {
    map<char, int> precedence;
    string myStr;
public:
    Shunting(string str){
        myStr = str;
        precedence.insert(pair<char, int>('+', 1));
        precedence.insert(pair<char, int>('-', 1));
        precedence.insert(pair<char, int>('*', 2));
        precedence.insert(pair<char, int>('/', 2));
    }
    int getPrec(char c) const;
    Expression* applyOp(Expression* a, Expression* b, char op);
    Expression* evaluate(string tokens);
    string getStr();
};


#endif //UNTITLED5_SHUNTING_H
