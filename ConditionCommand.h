//
// Created by daniella on 12/19/18.
//

#ifndef UNTITLED5_CONDITIONCOMMAND_H
#define UNTITLED5_CONDITIONCOMMAND_H


#include "Command.h"

class ConditionCommand: public Command {
    queue<string> args;
public:
    ConditionCommand(queue<string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }
    virtual double doCommand();
};


#endif //UNTITLED5_CONDITIONCOMMAND_H
