//
// Created by noam on 12/20/18.
//

#include "PrintCommand.h"

int PrintCommand::execute() {
    if (this->maps.getVarsValuesMap().count(this->line[1]) > 0) {
        this->line[1] = to_string(this->maps.getVarsValuesMap().find(this->line[1])->second);
    }
    cout << this->line[1] << endl;
}