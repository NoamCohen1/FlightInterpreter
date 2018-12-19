//
// Created by gal on 12/19/18.
//

#ifndef INTERPRETERFLIGHT_EQUALCOMMAND_H
#define INTERPRETERFLIGHT_EQUALCOMMAND_H
#include "Command.h"
using namespace std;

class EqualCommand {
public:
    virtual int execute();

    virtual void setParams(vector<string> line) {

    }
};


#endif //INTERPRETERFLIGHT_EQUALCOMMAND_H
