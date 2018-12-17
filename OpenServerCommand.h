//
// Created by gal on 12/17/18.
//

#ifndef INTERPRETERFLIGHT_OPENSERVERCOMMAND_H
#define INTERPRETERFLIGHT_OPENSERVERCOMMAND_H

#include "Command.h"
#include "vector"
#include "string"

using namespace std;

class OpenServerCommand : public Command {
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_OPENSERVERCOMMAND_H
