//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_DEFINEVARCOMMAND_H
#define INTERPRETERFLIGHT_DEFINEVARCOMMAND_H

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
#include "EqualCommand.h"
#include "BindCommand.h"

class DefineVarCommand : public Command {
    Maps *maps;
    map<string, double> varsMap;
    vector<string> line;
public:
    virtual int execute();

    virtual void setParams(vector<string> line, Maps *maps) {
        this->line = line;
        this->maps = maps;
    }
};


#endif //INTERPRETERFLIGHT_DEFINEVARCOMMAND_H
