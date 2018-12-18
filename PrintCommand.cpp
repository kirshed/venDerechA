//
// Created by daniella on 12/17/18.
//

#include "PrintCommand.h"

using namespace std;

double PrintCommand::doCommand() {
    string strPrint = args.front();
    args.pop();
    cout <<strPrint <<endl;
    return 0;
}