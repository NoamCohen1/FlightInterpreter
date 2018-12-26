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

struct ClientParams {
    string ipAddress;
    int port;
    Maps *maps;
};

struct ServerParams {
    int port;
    int Hz;
    Maps *maps;
};

class Sockets {
    map<string, string> varPlaces;
public:
    static void *openServerSocket(void *arg);

    static void *openClientSocket(void *arg);
};

#endif //INTERPRETERFLIGHT_SOCKETS_H
