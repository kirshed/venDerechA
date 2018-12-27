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


void OpenDataServerCommand:: openReader(int new_socket, double readSpeed){
    OpenDataReader serverReader = OpenDataReader();
    serverReader.reader(new_socket, readSpeed);
}

double OpenDataServerCommand::doCommand() {
    queue<string> tempArgs = args;
    Shunting shunt = Shunting();
    double port = shunt.evaluate(tempArgs.front())->calculate();
    tempArgs.pop();
    double readSpeed = shunt.evaluate(tempArgs.front())->calculate();
    tempArgs.pop();
    /*
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }

    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    // Close listening socket
    close(listening);

    // While loop: accept and echo message back to client
    char buf[4096];

    while (true)
    {
        memset(buf, 0, 4096);

        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            break;
        }

        //cout << string(buf, 0, bytesReceived) << endl;

        // Echo message back to client
        //send(clientSocket, buf, bytesReceived + 1, 0);
    }

    // Close the socket
    close(clientSocket);

    return 0;
*/
    int server_fd, new_socket, valread;
    //char buffer[1024];
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    listen(server_fd, 5);
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                             (socklen_t*) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    //WILL OPEN A THREAD HERE
    //openReader(new_socket, buffer, readSpeed);
    thread first(openReader, new_socket, readSpeed);
    first.detach();
    //sleep(30);
    //while (true){}
    //return myReader.Reader();
    return 0;
}