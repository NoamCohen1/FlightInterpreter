//
// Created by gal on 12/17/18.
//

#include "OpenServerCommand.h"

//void* OpenServerCommand::thread_func(void* arg) {
//    Sockets* serverS;
//    serverS->openServerSocket(arg);
//}

int OpenServerCommand::execute() {
    if (line.size() != 3) {
        throw "The Number of Arguments is Not Correct";
    }
    InfixToPrefix infToPre(this->maps);
    vector<string> strings;
    vector<string> stringsConverted;
    vector<Expression*> expressions;
    for (int i = 1; i < line.size(); ++i) {
        strings = infToPre.convertToStrings(line[i]);
        stringsConverted = infToPre.convertFunc(strings);
        Expression *e = infToPre.turnToExppression(stringsConverted);
        expressions.push_back(e);
    }

    int socketPort = (int) expressions[0]->calculate();
    int Hz = (int) expressions[1]->calculate();

    struct ServerParams *params = new ServerParams();

    params->Hz = Hz;
    params->port = socketPort;
    params->maps = maps;

    pthread_t trid;
    pthread_create(&trid, nullptr, Sockets::openServerSocket, params);
    //pthread_join(&trid, &params);
    return 0;
}

