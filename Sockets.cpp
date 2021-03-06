#include "Sockets.h"

void *Sockets::openServerSocket(void *arg) {
    struct ServerParams *params = (struct ServerParams *) arg;
    char buffer[256];
    int n;
    bzero(buffer, 256);
    string buff;
    string leftOvers;

    params->maps->incCounter();
    /* If connection is established then start communicating */
    while (params->maps->getStateOfSockets()) {
        bzero(buffer, 256);
        n = read(params->maps->getSockfdServer(), buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        //printf(buffer);
        // split each line it get from the file to list of separate strings
        vector<double> info;
        size_t pos = 0;
        string delimiter = ",";
        string delimiter2 = "\n";
        buff += buffer;
        pos = buff.find(delimiter2);
        leftOvers += buff.substr((0, pos));
        // to remove the \n from the beginning of the string
        leftOvers = leftOvers.substr(1);
        buff.erase(pos + delimiter2.length() - 1);
        pos = 0;
        while ((pos = buff.find(delimiter)) != string::npos) {
            info.push_back(stod(buff.substr(0, pos)));
            buff.erase(0, pos + delimiter.length());
        }
        info.push_back(stoi(buff.substr(0, pos)));
        buff = "";
        params->maps->lock();
        params->maps->updateLocationsAndValMap(info);
        params->maps->unlock();
        //cout << "help" << endl;
        buff += leftOvers;
        leftOvers = "";
    }
    params->maps->decCounter();
    if (params->maps->getCounter() == 0)    {
        delete params->maps;
    }
}


void *Sockets::openClientSocket(void *arg) {
    struct ClientParams *params = (struct ClientParams *) arg;
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = params->port;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    params->maps->setSockfdClient(sockfd);

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



