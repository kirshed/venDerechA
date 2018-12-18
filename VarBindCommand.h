//
// Created by daniella on 12/18/18.
//

#ifndef UNTITLED5_VARBINDCOMMAND_H
#define UNTITLED5_VARBINDCOMMAND_H


#include "Command.h"

class VarBindCommand: public Command {
    queue<string> args;
public:
    VarBindCommand(queue<string> ar){
        args = ar;
    }

    virtual double doCommand();

};


#endif //UNTITLED5_VARBINDCOMMAND_H
