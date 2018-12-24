//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_COMMAND_H
#define INTERPRETERFLIGHT_COMMAND_H

#include <iostream>
#include "Expression.h"
#include "vector"
#include "string.h"
#include "Maps.h"

using namespace std;

class Command {
public:
    virtual int execute() = 0;

    virtual void setParams(vector<string> line, Maps *maps) = 0;
};


#endif //INTERPRETERFLIGHT_COMMAND_H
