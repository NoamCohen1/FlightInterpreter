//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_CONNECTCOMMAND_H
#define INTERPRETERFLIGHT_CONNECTCOMMAND_H

#include "vector"
#include "string"
#include <pthread.h>
#include "InfixToPrefix.h"
#include "Command.h"
#include "Sockets.h"
#include "Maps.h"

using namespace std;

struct ClientParams {
    string ipAddress;
    int port;
    Maps maps;
};

class ConnectCommand : public Command {
    Maps maps;
    vector<string> line;
public:
    virtual int execute();

    static void* thread_func(void* arg);

    virtual void setParams(vector<string> line) {
        this->line = line;
    }

};


#endif //INTERPRETERFLIGHT_CONNECTCOMMAND_H
