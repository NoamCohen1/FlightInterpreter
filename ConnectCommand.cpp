//
// Created by noam on 12/18/18.
//

#include "ConnectCommand.h"

//void* ConnectCommand::thread_func(void* arg) {
//    Sockets* serverS;
//    serverS->openClientSocket(arg);
//}

void ConnectCommand::execute() {
    if (line.size() != 3) {
        throw "The Number of Arguments is Not Correct";
    }
    InfixToPrefix infToPre(this->maps);
    vector<string> strings;
    vector<string> stringsConverted;
    vector<Expression*> expressions;
    strings = infToPre.convertToStrings(line[2]);
    stringsConverted = infToPre.convertFunc(strings);
    Expression *e = infToPre.turnToExppression(stringsConverted);
    expressions.push_back(e);
    string ipAddress = line[1];
    int port = (int) expressions[0]->calculate();

    struct ClientParams *params = new ClientParams();
    params->ipAddress = ipAddress;
    params->port = port;
    params->maps = maps;
    //Sockets* serverS;
    pthread_t trid;
    pthread_create(&trid, nullptr, Sockets::openClientSocket, params);
    //pthread_join(&trid, &params);
}