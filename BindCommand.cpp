//
// Created by noam on 12/20/18.
//

#include "BindCommand.h"

int BindCommand::execute() {
    this->maps.updateBindsMap(line[1], line[4]);
    if (this->maps.getLocationsAndValMap().count(line[4]) > 0) {
        this->maps.updateVarsValuesMap(line[1], this->maps.getLocationsAndValMap().find(line[4])->second);
    }
}