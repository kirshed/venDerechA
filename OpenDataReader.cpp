//
// Created by daniella on 12/20/18.
//

#include "OpenDataReader.h"

//
// Created by daniella on 12/17/18.
//

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <chrono>
#include <thread>
#include "OpenDataServerCommand.h"

using namespace std;

double OpenDataReader::reader(int new_socket, double readSpeed) {
    /*while(myRead>=0){
        clock_t time_start;
        time_start = clock();
        myRead = read(new_socket, buffer, 5000);
        updateMaps(buffer);
        //printf("%s\n", buffer);
        clock_t time_end;
        time_end = time_start+10*readSpeed*CLOCKS_PER_SEC/1000;
        //need to unlock the mutex
        while (clock()<time_end){}
    }*/
    /*char buffer[1024];
    int isFirst = 0;
    while (true) {
        ssize_t myRead = 0;
        int i = 0;
        char lastChar ='\0';
        while (i < 1024 && lastChar != '\n') {
            myRead = read(new_socket, buffer+i, 1);
            cout<< buffer<<endl;
            updateMaps(buffer, isFirst);
            isFirst = 1;
            lastChar = buffer[i];
            i++;
        }
        sleep((unsigned int) 1 / readSpeed);
    }
    close(new_socket);
    return 0;*/
    char c = '\0';
    int n;
    string data;
    if(new_socket<0){
        perror("ERROR");
    }
    //n = read(new_socket, &c, 1);
    while(true) {
        while (c != '\n') {
            if (n < 0) {
                perror("ERROR");
                exit(1);
            }
            n = read(new_socket, &c, 1);
            data += c;
        }
        cout<< data<< endl;
        char *cstr = new char[data.length() + 1];
        strcpy(cstr, data.c_str());
        updateMaps(cstr, 0);
    }
}

void OpenDataReader:: updateMaps(char* buffer, int isFirst){
    int in = 1;
    const char *ch = buffer;
    string str(ch);
    int size = str.find("\n");
    /*if(isFirst>0&& size<str.size()){
        str.erase(0,size + 1);
        size =  str.find("\n");
        str.erase(size,str.size());
    }*/
    str = str.substr(0, size);
    string strVal;
    double numVal;
    for(int i = 0; i<str.size()-1;i++){
        //cout<< "made it"<< endl;
        if(str[i] == ' '){
            continue;
        }
        else if(str[i] == ','){
            //current double value
            numVal = stoi(strVal.c_str());
            //update path double according to index
            data.updatePathByInt(in, numVal);
            //get path according to index
            string path = data.getPathByIndex(in);
            //update val double according to path
            data.updateSymbolTableByPath(path, numVal);
            in+=1;
            strVal = "";
            continue;
        }
        strVal+=str[i];
    }
}