//
// Created by daniella on 12/20/18.
//

#include "mapsData.h"

map<string, double> mapsData::getSymbolTable() {
    return symbolTable;
}

map<string, string> mapsData::getVarPaths() {
    return varPaths;
}

map<string, double> mapsData::getPathValues() {
    return pathValues;
}

void mapsData::addSymbol(string str, double dbl) {
    symbolTable.insert(pair<string, double>(str, dbl));
}

void mapsData::makePathValues() {
    pathValues = {{"1/instrumentation/airspeed-indicator/indicated-speed-kt",         0},
                  {"2/instrumentation/altimeter/indicated-altitude-ft",               0},
                  {"3/instrumentation/altimeter/pressure-alt-ft",                     0},
                  {"4/instrumentation/attitude-indicator/indicated-pitch-deg",        0},
                  {"5/instrumentation/attitude-indicator/indicated-roll-deg",         0},
                  {"6/instrumentation/attitude-indicator/internal-pitch-deg",         0},
                  {"7/instrumentation/attitude-indicator/internal-roll-deg",          0},
                  {"8/instrumentation/encoder/indicated-altitude-ft",                 0},
                  {"9/instrumentation/encoder/pressure-alt-ft",                       0},
                  {"10/instrumentation/gps/indicated-altitude-ft",                    0},
                  {"11/instrumentation/gps/indicated-ground-speed-kt",                0},
                  {"12/instrumentation/gps/indicated-vertical-speed",                 0},
                  {"13/instrumentation/heading-indicator/indicated-heading-deg",      0},
                  {"14/instrumentation/magnetic-compass/indicated-heading-deg",       0},
                  {"15/instrumentation/slip-skid-ball/indicated-slip-skid",           0},
                  {"16/instrumentation/turn-indicator/indicated-turn-rate",           0},
                  {"17/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0},
                  {"18/controls/flight/aileron",                                      0},
                  {"19/controls/flight/elevator",                                     0},
                  {"20/controls/flight/rudder",                                       0},
                  {"21/controls/flight/flaps",                                        0},
                  {"22/controls/engines/engine/throttle",                             0},
                  {"23/engines/engine/rpm",                                           0}};
}

//adds a new var and path to map
void mapsData:: addVPath(string v, string p){
    //adding var and path to varPaths
    varPaths.insert(pair<string, string> (v, p));
}

//adds a val to symbol table accoring to path
int mapsData:: addSymAndDoubleByPath(string v, string p){
    for(map<string,double>::iterator it=pathValues.begin(); it!=pathValues.end(); ++it){
        unsigned long int slash = it->first.find("/");
        //cutting path from map without index
        string thisPath = it->first.substr(slash, it->first.size());
        if(p == thisPath){
            //adding val and double to symbolTable
            addSymbol(v, it->second);
            return 1;
        }
    }
    //if no path was found
    throw "no such path";
}

//updates path according to index
void mapsData:: updatePathByInt(int index, double value){
        int num;
    for(map<string,double>::iterator it=pathValues.begin(); it!=pathValues.end(); ++it){
        unsigned long int slash = it->first.find("/");
        //will take the int at the begining of the path
        string temp = it->first.substr(0, slash);
        num = stoi(temp.c_str());
        //index = current path
        if(num == index){
            //updating paths double
            it->second = value;
        }

    }
}

//returns path according to index
string mapsData:: getPathByIndex(int index){
    for(map<string,double>::iterator it=pathValues.begin(); it!=pathValues.end(); ++it){
        unsigned long int slash = it->first.find("/");
        //will be the path index
        string str = it->first.substr(0, slash);
        int pindex = stoi(str.c_str());
        if(index == pindex){
            //returns path without index at the begining
            return it->first.substr(slash+1, it->first.size());
        }
    }
    throw "no such index in path map";
}

void mapsData:: updateSymbolTableByPath(string path, double value){
    path = "/"+path;
    for(map<string,string>::iterator it=varPaths.begin(); it!=varPaths.end(); ++it){
        if(path == it->second){
            symbolTable[ it->first ] = value;
        }
    }
}

int mapsData:: updateSymDoubleByVar(string var, double value){
    for(map<string,double>::iterator it=symbolTable.begin(); it!=symbolTable.end(); ++it){
        if(it->first == var){
            symbolTable[var] = value;
            return 1;
        }
    }
    throw "variable does not exist";
}

void mapsData:: updatePathDoubleByVar(string var, double value){
    for(map<string,string>::iterator it=varPaths.begin(); it!=varPaths.end(); ++it){
        if (var == it->first){
            for(map<string, double>::iterator innerIt=pathValues.begin(); innerIt!=pathValues.end(); ++innerIt){
                unsigned long int slash = innerIt->first.find("/");
                string curPath = innerIt->first.substr(slash, innerIt->first.size());
                //it->second = the vars path
                if(it->second == curPath){
                    //innetIt->first = the path of the relevant var
                    pathValues[innerIt->first] = value;
                    return;
                }
            }
        }
    }
    throw "could not update path value";
}

void mapsData::setIsNewData(bool isNew) {
    isNewData = isNew;
}

bool mapsData:: getIsNewData(){
    return isNewData;
}

void mapsData::setNewVar(string str) {
    newVar = str;
}

string mapsData::getNewVar(){
    return newVar;
}

string mapsData:: getPathByVar(string var){
    for(map<string,string>::iterator it=varPaths.begin(); it!=varPaths.end(); ++it){
        if(it->first == var){
            return it->second;
        }
    }
}

double mapsData:: getvaluebyvar(string var){
   for(map<string,double>::iterator it=symbolTable.begin(); it!=symbolTable.end(); ++it){
       if(it->first == var){
           return it->second;
       }
   }
}