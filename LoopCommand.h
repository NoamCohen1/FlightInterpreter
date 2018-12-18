//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_LOOPCOMMAND_H
#define INTERPRETERFLIGHT_LOOPCOMMAND_H

#include "ConditionParser.h"

class LoopCommand : public ConditionParser {
    vector<vector<string>> commands;
public:
    LoopCommand(vector<vector<string>> commands) {
        this->commands = commands;
    }

    virtual int execute();

    virtual void setParams(vector<string> line) {}
};


#endif //INTERPRETERFLIGHT_LOOPCOMMAND_H
