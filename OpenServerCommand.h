//
// Created by gal on 12/17/18.
//

#ifndef INTERPRETERFLIGHT_OPENSERVERCOMMAND_H
#define INTERPRETERFLIGHT_OPENSERVERCOMMAND_H

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

class OpenServerCommand : public Command {
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_OPENSERVERCOMMAND_H
