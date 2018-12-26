//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_WHILECOMMAND_H
#define UNTITLED5_WHILECOMMAND_H

#include <queue>
#include "Expression.h"
#include "Command.h"

class WhileCommand: public Command {
    queue <Expression*> args;
public:
    WhileCommand(queue <Expression*> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }
    virtual double doCommand();
};


#endif //UNTITLED5_WHILECOMMAND_H
