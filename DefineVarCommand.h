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

class DefineVarCommand : public Command {
    map<string, double> varsMap;
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_DEFINEVARCOMMAND_H
