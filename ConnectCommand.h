//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_CONNECTCOMMAND_H
#define UNTITLED5_CONNECTCOMMAND_H

#include "Command.h"


class ConnectCommand: public Command {
public:
    ConnectCommand(){

    }
    virtual int doCommand();
};


#endif //UNTITLED5_CONNECTCOMMAND_H
