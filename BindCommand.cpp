#include "BindCommand.h"

void BindCommand::execute() {
    // update the var and path map
    // if the value is also a var we get its path
    if (this->maps->getBindsMap().count(line[4]) > 0) {
        this->maps->updateBindsMap(line[1], this->maps->getBindsMap().find(line[4])->second);
    } else {
        // if the value is a path
        this->maps->updateBindsMap(line[1], line[4]);
    }
    // if this path is in the xml we update the value of the var
    if (this->maps->getLocationsAndValMap().count(line[4]) > 0) {
        this->maps->updateVarsValuesMap(line[1], this->maps->getValueFromLocation(line[4]));
    } else {
        // if this path does not exist in the xml - initialize with 0
        this->maps->updateVarsValuesMap(line[1], 0.0);
    }
}