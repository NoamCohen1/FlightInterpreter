//
// Created by noam on 12/20/18.
//

#ifndef INTERPRETERFLIGHT_BINDCOMMAND_H
#define INTERPRETERFLIGHT_BINDCOMMAND_H

#include "vector"
#include "string"
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <iostream>
#include "InfixToPrefix.h"
#include "Command.h"
#include "Maps.h"

class BindCommand : public Command {
    Maps maps;
    map<string, double> varsMap;
    vector<string> line;
public:
    virtual int execute();

    virtual void setParams(vector<string> line, Maps maps) {
        this->line = line;
        this->maps = maps;
    }
};


#endif //INTERPRETERFLIGHT_BINDCOMMAND_H
