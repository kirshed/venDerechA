//
// Created by daniella on 12/17/18.
//

#include "VarCommand.h"


double VarCommand:: doCommand(){
    queue<string> tempArgs = args;
    Shunting myShunt = Shunting();
    string var = tempArgs.front();
    tempArgs.pop();
    double value = myShunt.evaluate(tempArgs.front())->calculate();
    tempArgs.pop();
    //adding new var and value to symbolTable
    data.addSymbol(var, value);
    return value;
}