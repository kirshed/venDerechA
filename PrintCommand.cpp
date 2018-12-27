//
// Created by daniella on 12/17/18.
//

#include "PrintCommand.h"

using namespace std;

double PrintCommand::doCommand() {
    queue<string> tempArgs = args;
    string strPrint = tempArgs.front();
    tempArgs.pop();
    unsigned long int gersh = strPrint.find('"');
    unsigned long int x = -1;
    //there are " in the string which means i just need to pront the sentect as is
    if(gersh !=x){
        strPrint = strPrint.substr(gersh+1, strPrint.size()-1);
        cout <<strPrint <<endl;
        return 0;
    }
    //we need to pront the value of a var
    double value = data.getSymbolTable()[strPrint];
    cout<< value<< endl;
    return 0;
}