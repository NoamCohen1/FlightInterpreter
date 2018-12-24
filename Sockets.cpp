#include "Sockets.h"

void *Sockets::openServerSocket(void *arg) {
    struct ServerParams *params = (struct ServerParams *) arg;
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

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

    /* If connection is established then start communicating */
    bzero(buffer, 256);
    while (true) {
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        // split each line it get from the file to list of separate strings
        vector<double> info;
        size_t pos = 0;
        string delimiter = ",";
        string buff = buffer;
        while ((pos = buff.find(delimiter)) != string::npos) {
            info.push_back(stoi(buff.substr(0, pos)));
            buff.erase(0, pos + delimiter.length());
        }
        info.push_back(stoi(buff.substr(0, pos)));
        params->maps.updateLocationsAndValMap(info);
    }

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n", buffer);

    /* Write a response to the client */
    n = write(newsockfd, "I got your message", 18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    return 0;
}


void *Sockets::openClientSocket(void *arg) {
    struct ClientParams *params = (struct ClientParams *) arg;
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

//    char buffer[256];

//    if (argc < 3) {
//        fprintf(stderr,"usage %s hostname port\n", argv[0]);
//        exit(0);
//    }

    portno = params->port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    params->maps.setSockfd(sockfd);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(params->ipAddress.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return 0;
}


//void *Sockets::updateData(void *arg) {
//    struct ClientParams *params = (struct ClientParams *) arg;
//    char buffer[256];
//    int n;
//    /* Now ask for a message from the user, this message
//       * will be read by server
//    */
//
//    printf("Please enter the message: ");
//    bzero(buffer, 256);
//    fgets(buffer, 255, stdin);
//
////    /* Send message to the server */
////    n = write(params->maps.getSockfd(), buffer, strlen(buffer));
////
////    if (n < 0) {
////        perror("ERROR writing to socket");
////        exit(1);
////    }
//
//    /* Now read server response */
//    bzero(buffer, 256);
//    n = read(params->maps.getSockfd(), buffer, 255);
//
//    if (n < 0) {
//        perror("ERROR reading from socket");
//        exit(1);
//    }
//
//    printf("%s\n", buffer);
//}


//void Sockets::func1() {
//    pthread_t trid;
//    pthread_create(&trid, nullptr, openServerSocket, nullptr);
//
//
//}