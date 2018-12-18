//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_CONNECTCOMMAND_H
#define INTERPRETERFLIGHT_CONNECTCOMMAND_H

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

using namespace std;

class ConnectCommand : public Command {
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_CONNECTCOMMAND_H
