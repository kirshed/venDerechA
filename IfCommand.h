//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_IFCOMMAND_H
#define UNTITLED5_IFCOMMAND_H


#include "Command.h"

class IfCommand: public Command {
public:
    IfCommand(){

    }

    virtual int doCommand();
};


#endif //UNTITLED5_IFCOMMAND_H
