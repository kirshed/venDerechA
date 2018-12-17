//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_PRINTCOMMAND_H
#define UNTITLED5_PRINTCOMMAND_H

#include "Command.h"
class PrintCommand: public Command {
public:
    PrintCommand(){}
    virtual int doCommand();
};


#endif //UNTITLED5_PRINTCOMMAND_H
