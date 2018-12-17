//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_OPENDATASERVERCOMMAND_H
#define UNTITLED5_OPENDATASERVERCOMMAND_H


#include <string>
#include "Command.h"
#include "vector"
#include "string.h"

using namespace std;

class OpenDataServerCommand: public Command {
public:
    OpenDataServerCommand(){

    }
    virtual int doCommand();
};


#endif //UNTITLED5_OPENDATASERVERCOMMAND_H
