//
// Created by daniella on 12/17/18.
//

#include "PrintCommand.h"

using namespace std;

double PrintCommand::doCommand() {
    queue<string> tempArgs = args;
    string strPrint = tempArgs.front();
    tempArgs.pop();
    cout <<strPrint <<endl;
    return 0;
}