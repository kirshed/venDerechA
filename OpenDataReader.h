//
// Created by daniella on 12/20/18.
//

#ifndef UNTITLED5_OPENDATAREADER_H
#define UNTITLED5_OPENDATAREADER_H

#include <string>
#include <queue>
#include "vector"
#include "string.h"
#include "mapsData.h"

using namespace std;

extern mapsData data;
extern bool shouldStop;

class OpenDataReader {
public:
    //queue <string> args;
    OpenDataReader(){
        //not emptying ar here because i don't want to empty args form opendataserver
    }
    double reader(int new_socket, double readSpeed);
    void updateMaps(char* buffer, int isFirst);
};


#endif //UNTITLED5_OPENDATAREADER_H
