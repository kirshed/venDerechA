//
// Created by daniella on 12/16/18.
//

#ifndef UNTITLED5_EXPARSE_H
#define UNTITLED5_EXPARSE_H

#include <list>
#include <string>
#include <vector>
#include <map>
#include "string.h"
#include "fstream"
#include "CommandExpression.h"
enum comEnum{SERVER, CONNECT, VAR, WHILE, IF, SLEEP, OTHER};
using namespace std;


class LexParse {
    vector<string> lexed;
    map<string, Expression*> ceMap;
    map<string, double> varMap;
public:
    LexParse(){
        list<string> lexed;
    }
    void lexer(ifstream& data);
    void parser();
};


#endif //UNTITLED5_EXPARSE_H
