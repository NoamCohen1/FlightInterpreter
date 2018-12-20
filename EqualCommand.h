//
// Created by gal on 12/19/18.
//

#ifndef INTERPRETERFLIGHT_EQUALCOMMAND_H
#define INTERPRETERFLIGHT_EQUALCOMMAND_H

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

class EqualCommand : public Command {
    Maps maps;
    map<string, double> varsMap;
    vector<string> line;
public:
    virtual int execute();

    virtual void setParams(vector<string> line) {
        this->line = line;
    }
};

#endif //INTERPRETERFLIGHT_EQUALCOMMAND_H