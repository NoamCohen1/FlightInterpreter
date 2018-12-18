//
// Created by gal on 12/17/18.
//

#ifndef INTERPRETERFLIGHT_EXPRESSIONCOMMAND_H
#define INTERPRETERFLIGHT_EXPRESSIONCOMMAND_H

#include "Command.h"
#include "Expression.h"

class ExpressionCommand : public Expression {
    Command *command;
public:
    ExpressionCommand(Command *command){
        this->command = command;
    }

    Command* getCommand () {
        return this->command;
    }

    virtual double calculate();
};


#endif //INTERPRETERFLIGHT_EXPRESSIONCOMMAND_H
