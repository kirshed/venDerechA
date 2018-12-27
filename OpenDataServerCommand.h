//
// Created by daniella on 12/17/18.
//

#ifndef UNTITLED5_OPENDATASERVERCOMMAND_H
#define UNTITLED5_OPENDATASERVERCOMMAND_H


#include <string>
#include "Command.h"
#include "vector"
#include "string.h"
#include "OpenDataReader.h"

using namespace std;


class OpenDataServerCommand: public Command {
    queue <string> args;
public:
    OpenDataServerCommand(queue <string> &ar) : args(ar){
        while(!ar.empty()){
            ar.pop();
        }
    }
    static void openReader(int new_socket, double readSpeed);
    virtual double doCommand();
};


#endif //UNTITLED5_OPENDATASERVERCOMMAND_H
