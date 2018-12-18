//
// Created by noam on 12/13/18.
//

#ifndef INTERPRETERFLIGHT_COMMAND_H
#define INTERPRETERFLIGHT_COMMAND_H

#include "Expression.h"
#include "vector"
#include "string.h"
#include <iostream>

using namespace std;

class Command {
public:
    virtual int execute(vector<string> line) = 0;
};


#endif //INTERPRETERFLIGHT_COMMAND_H
