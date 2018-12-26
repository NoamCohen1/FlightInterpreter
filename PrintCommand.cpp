#include "PrintCommand.h"

void PrintCommand::execute() {
    maps->replaceVarByValueForPrint(this->line);
    cout << this->line[1] << endl;
}


