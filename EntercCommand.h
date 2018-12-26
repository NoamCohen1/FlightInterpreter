#ifndef INTERPRETERFLIGHT_ENTERCCOMMAND_H
#define INTERPRETERFLIGHT_ENTERCCOMMAND_H

#include <vector>
#include <string>
#include <pthread.h>
#include "Command.h"

using namespace std;

class EntercCommand : public Command {
    Maps *maps;
    vector<string> line;
public:
    virtual void execute();

    virtual void setParams(vector<string> line, Maps *maps) {
        this->line = line;
        this->maps = maps;
    }
};



#endif //INTERPRETERFLIGHT_ENTERCCOMMAND_H
