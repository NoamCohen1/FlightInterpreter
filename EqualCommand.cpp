//
// Created by gal on 12/19/18.
//

#include "EqualCommand.h"

void EqualCommand::execute() {
    string s = this->line[2];
    double d = 0;
    // calculate the value
    InfixToPrefix infToPre(this->maps);
    vector<string> strings;
    vector<string> stringsConverted;
    strings = infToPre.convertToStrings(s);
    stringsConverted = infToPre.convertFunc(strings);
    Expression *e = infToPre.turnToExppression(stringsConverted);
    d = e->calculate();
    // replace the var value in the map to the new value or add a new var and value to the map
    this->maps->updateVarsValuesMap(this->line[0], d);
    string newValue;
    // write the new value to the server
    if ((this->maps->getBindsMap().count(this->line[0])) > 0) {
        newValue = "set " + this->maps->getBindsMap().find(this->line[0])->second + " " + to_string(d) + "\r\n";
        this->setValue(newValue);
    }
}

void EqualCommand::setValue(string newValue) {
    int sockfd = this->maps->getSockfdClient();
    char *c = const_cast<char*>(newValue.c_str());
    /* Send message to the server */
    int n = write(sockfd, c, strlen(c));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}