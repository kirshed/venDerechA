//
// Created by daniella on 12/17/18.
//

#include "WhileCommand.h"

double WhileCommand::doCommand() {
    queue<Expression*> tempArgs = args;
//first args is condition
    Expression* con = tempArgs.front();
    tempArgs.pop();
    vector<Expression*> vecArgs;
    int i;
    while(!tempArgs.empty()){
        vecArgs.push_back(tempArgs.front());
        tempArgs.pop();
    }
    while(con->calculate()){
        for(i = 0;i<vecArgs.size();i++){
            vecArgs.at(i)->calculate();
        }
        i = 0;
    }
    return 0;
}