//
// Created by noam on 12/20/18.
//

#ifndef INTERPRETERFLIGHT_PRINTCOMMAND_H
#define INTERPRETERFLIGHT_PRINTCOMMAND_H

#include <vector>
#include <string>
#include <pthread.h>
#include "InfixToPrefix.h"
#include "Command.h"
#include "Sockets.h"
#include "Maps.h"

using namespace std;

class PrintCommand : public Command {
    Maps *maps;
    vector<string> line;
public:
    virtual void execute();

    //static void* thread_func(void* arg);

    virtual void setParams(vector<string> line, Maps *maps) {
        this->line = line;
        this->maps = maps;
    }
};

#endif //INTERPRETERFLIGHT_PRINTCOMMAND_H
