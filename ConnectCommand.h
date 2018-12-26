//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_CONNECTCOMMAND_H
#define UNTITLED5_CONNECTCOMMAND_H

#include "Command.h"
#include "ClientWriter.h"


class ConnectCommand: public Command {
    queue <string> args;
public:
    ConnectCommand(queue <string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }
    static void openWriter(queue<string> args);
    virtual double doCommand();
};


#endif //UNTITLED5_CONNECTCOMMAND_H
