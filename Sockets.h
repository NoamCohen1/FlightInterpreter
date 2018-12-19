//
// Created by gal on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_SOCKETS_H
#define INTERPRETERFLIGHT_SOCKETS_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include <map>
#include <iostream>

#include <pthread.h>

#include <sys/socket.h>
#include "Maps.h"

using namespace std;

class Sockets {
    struct sockaddr_in planeSocket;
    struct sockaddr_in clientSocket;
    map<string,string> varPlaces;
    int id;
public:
    Sockets(){
        this->planeSocket.sin_addr.s_addr = 0;
        this->planeSocket.sin_family = 0;
        this->planeSocket.sin_port = 0;
        for(int i=0;i<8;i++) {
            this->planeSocket.sin_zero[i] = 0;
        }
    }

    void openFlightSocket(string s);
    void openClientSocket(string s);
    static void* getFlightSocket(void* arg);
    void* getClientSocket();
    void DataReader();

    static void* openServerSocket(void* arg);
    static void* openClientSocket(void* arg);
    void* updateData(void *arg);
        //void func1();
    };


#endif //INTERPRETERFLIGHT_SOCKETS_H
