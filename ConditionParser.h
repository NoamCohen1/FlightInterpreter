//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_CONDITIONPARSER_H
#define INTERPRETERFLIGHT_CONDITIONPARSER_H

#include <map>
#include "Command.h"

class ConditionParser : public Command {
    map<string, Expression*> commandsMap;
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_CONDITIONPARSER_H
