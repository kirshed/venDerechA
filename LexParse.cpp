//
// Created by daniella on 12/16/18.
//

#include "LexParse.h"

using namespace std;

void LexParse:: lexer(ifstream& data){
    string str;
    string temp;
    while (getline(data, str)) {
        //adds each string command to list
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            long long int index = 0;
            index = str.find(" ", 0);
            temp = str.substr(0, index);
            lexed.push_back(temp);
            str.substr(index+1, str.size());
        }
    }
}
