//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_LOOPCOMMAND_H
#define INTERPRETERFLIGHT_LOOPCOMMAND_H

#include "ConditionParser.h"

class LoopCommand : public ConditionParser {
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_LOOPCOMMAND_H
