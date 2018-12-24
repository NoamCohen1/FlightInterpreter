//
// Created by gal on 12/17/18.
//

#ifndef INTERPRETERFLIGHT_OPENSERVERCOMMAND_H
#define INTERPRETERFLIGHT_OPENSERVERCOMMAND_H

#include "vector"
#include "string"
#include <pthread.h>
#include "InfixToPrefix.h"
#include "Command.h"
#include "Sockets.h"
#include "Maps.h"

using namespace std;

//struct ServerParams {
//    int port;
//    int Hz;
//    Maps maps;
//};

class OpenServerCommand : public Command {
    Maps maps;
    vector<string> line;
public:
    virtual int execute();

    static void* thread_func(void* arg);

    virtual void setParams(vector<string> line, Maps maps) {
        this->line = line;
        this->maps = maps;
    }
};


#endif //INTERPRETERFLIGHT_OPENSERVERCOMMAND_H
