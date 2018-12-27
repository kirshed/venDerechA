//
// Created by daniella on 12/16/18.
//
#ifndef UNTITLED9_LEXPARSE_H
#define UNTITLED9_LEXPARSE_H


#include <string>
#include <vector>
#include <map>
#include "string.h"
#include "fstream"
#include "CommandExpression.h"
#include <queue>
#include <iostream>

using namespace std;

extern bool shouldStop;

class LexParse {
    map<int, vector<string>> commandsMap;
    map<char, int> sign;
    vector<CommandExpression *> delCom;
    vector<CommandExpression *> delCVec;
public:

    LexParse() {

    }

    void lexer(vector<string> lines);
    void initializeSign();
    vector<string> createString(string l);
    vector<string> fromStringToExp(vector<string> str);
    vector<CommandExpression*> parser(map<int, vector<string>> commandsMap);
};

#endif //UNTITLED9_LEXPARSE_H
