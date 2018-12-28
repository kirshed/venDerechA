//
// Created by daniella on 12/22/18.
//

#include <mutex>
#include "ClientWriter.h"

mutex myMutex;
extern bool shouldStop;

double ClientWriter::writeToServer() {
//cout<<"shit";
    queue<string> tempArgs = args;

    Shunting shunt = Shunting();
    string ip = tempArgs.front();
    tempArgs.pop();
    string portStr = tempArgs.front();
    double portNum =  shunt.evaluate(portStr)->calculate();
    tempArgs.pop();
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char* cIp = const_cast<char*>(ip.c_str());

    string buffer;
/*
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }*/

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(cIp);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portNum);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while(true){
        if(data.getIsNewData()){
            queue<string>* newVars = data.getNewVars();
            while(!newVars->empty()){
                string path = data.getPathByVar(newVars->front());
                double value = data.getvaluebyvar(newVars->front());
                newVars->pop();
                buffer = "set " + path + " "+ to_string(value) + " \r\n";
                const char *charBuf = buffer.c_str();
                //cout<< buffer<< endl;
                //myMutex.lock();
                n = write(sockfd, charBuf, strlen(charBuf));
                //myMutex.unlock();
                //because i already updated the most recent var
                data.setIsNewData(false);
                //myMutex.unlock();
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }
            }
        }
        //cout<<"made it"<<endl;
    }
    /* Send message to the server */


    /* Now read server response
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }*/

    cout<< buffer;
    return 0;
}