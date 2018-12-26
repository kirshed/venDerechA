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
#include "mapsData.h"

using namespace std;

extern mapsData data;

class Shunting {
    map<char, int> precedence;
public:
    Shunting(){
        precedence.insert(pair<char, int>('+', 1));
        precedence.insert(pair<char, int>('-', 1));
        precedence.insert(pair<char, int>('*', 2));
        precedence.insert(pair<char, int>('/', 2));
    }
    int getPrec(char c) const;
    Expression* applyOp(Expression* a, Expression* b, char op);
    Expression* evaluate(string tokens);
    string getStr();
    string fixString(string exp);
};


#endif //UNTITLED5_SHUNTING_H
