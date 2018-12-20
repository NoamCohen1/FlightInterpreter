//
// Created by noam on 12/18/18.
//

#include "LoopCommand.h"

int LoopCommand::execute() {
    while (checkCondition(this->commands[0][1])) {
        for (int i = 0; i < this->commands.size(); ++i) {
            Expression *c = commandsMap.find(this->commands[i][0])->second;
            if (c == nullptr) {
                string s = this->maps.getBindsMap().find(info[0])->second;
                if (s != "") {
                    Expression *c = commandsMap.find(info[1])->second;
                    dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info);
                    c->calculate();
                }
            } else {
                dynamic_cast<ExpressionCommand *> (c)->getCommand()->setParams(info);
                c->calculate();
            }
        }
    }
}