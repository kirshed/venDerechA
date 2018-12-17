//
// Created by daniella on 12/16/18.
//

#ifndef UNTITLED5_EXPARSE_H
#define UNTITLED5_EXPARSE_H

#include <list>
#include <string>
#include "string.h"
#include "fstream"

using namespace std;


class LexParse {
    list<string> lexed;
public:
    LexParse(){
        list<string> lexed;
    }
    void lexer(ifstream& data);
};


#endif //UNTITLED5_EXPARSE_H
