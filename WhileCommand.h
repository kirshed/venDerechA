//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_WHILECOMMAND_H
#define UNTITLED5_WHILECOMMAND_H

#include "Command.h"

class WhileCommand: public Command {
    queue <string> args;
public:
    WhileCommand(queue <string> ar){
        args = ar;
    }
    virtual double doCommand();
};


#endif //UNTITLED5_WHILECOMMAND_H
