#ifndef INTERPRETERFLIGHT_EQUALCOMMAND_H
#define INTERPRETERFLIGHT_EQUALCOMMAND_H

#include <vector>
#include <string>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>
#include "InfixToPrefix.h"
#include "Command.h"
#include "Maps.h"

class EqualCommand : public Command {
    Maps *maps;
    map<string, double> varsMap;
    vector<string> line;
public:
    virtual void execute();

    void setValue(string newValue);

    virtual void setParams(vector<string> line, Maps *maps) {
        this->line = line;
        this->maps = maps;
    }
};

#endif //INTERPRETERFLIGHT_EQUALCOMMAND_H
