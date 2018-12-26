#include "OpenServerCommand.h"

void OpenServerCommand::execute() {
    if (line.size() != 3) {
        throw "The Number of Arguments is Not Correct";
    }
    InfixToPrefix infToPre(this->maps);
    vector<string> strings;
    vector<string> stringsConverted;
    vector<Expression *> expressions;
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

    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;


    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = params->port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    maps->setSockfdServer(newsockfd);
    maps->setStateOfSockets(true);

    pthread_t trid;
    pthread_create(&trid, nullptr, Sockets::openServerSocket, params);
    //pthread_join(&trid, &params);
}

