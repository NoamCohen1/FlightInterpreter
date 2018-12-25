//
// Created by noam on 12/20/18.
//

#include "PrintCommand.h"

void PrintCommand::execute() {
    int toPrint = 0;
    string help = "";
    InfixToPrefix infToPre(this->maps);
    vector<string> splitedString;
    vector<string> result;
    splitedString = infToPre.convertToStrings(this->line[1]);
    result = infToPre.convertFunc(splitedString);
    Expression *e = infToPre.turnToExppression(result);
    toPrint = e->calculate();
    cout << toPrint << endl;
}


