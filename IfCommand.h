//
// Created by noam on 12/18/18.
//

#ifndef INTERPRETERFLIGHT_IFCOMMAND_H
#define INTERPRETERFLIGHT_IFCOMMAND_H

#include "ConditionParser.h"

class IfCommand : public ConditionParser {
public:
    virtual int execute(vector<string> line);

};


#endif //INTERPRETERFLIGHT_IFCOMMAND_H
