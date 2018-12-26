//
// Created by daniella on 12/17/18.
//

#include <thread>
#include "ConnectCommand.h"

void ConnectCommand:: openWriter(queue<string> args){
    ClientWriter cliWrite = ClientWriter(args);
    cliWrite.writeToServer();
}

double ConnectCommand:: doCommand(){
    queue<string> tempArgs = args;
    ClientWriter myClient = ClientWriter(tempArgs);
    thread second(openWriter, tempArgs);
    second.join();
    return 0;
}