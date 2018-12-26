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

    ~ExpressionCommand() {
        delete command;
    }
};


#endif //INTERPRETERFLIGHT_EXPRESSIONCOMMAND_H
