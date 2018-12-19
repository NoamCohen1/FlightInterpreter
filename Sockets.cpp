//
// Created by gal on 12/18/18.
//

//#include "Sockets.h"
//
//#include <iostream>
//#include "Sockets.h"
//
////server
//void Sockets::openFlightSocket(string s) {
//    int sockfd, newsockfd, portno, clilen;
//    // char buffer[256];
//    struct sockaddr_in cli_addr;
//    int n;
//
//    /* First call to socket() function */
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    this->id=sockfd;
//
//    if (sockfd < 0) {
//        perror("ERROR opening socket");
//        exit(1);
//    }
//
//    /* Initialize socket structure */
//    bzero((char *) &this->planeSocket, sizeof(this->planeSocket));
//    portno = atoi(s.c_str());
//
//    this->planeSocket.sin_family = AF_INET;
//    this->planeSocket.sin_addr.s_addr = INADDR_ANY;
//    this->planeSocket.sin_port = htons(portno);
//
//    /* Now bind the host address using bind() call.*/
//    if (bind(sockfd, (struct sockaddr *) &this->planeSocket, sizeof(this->planeSocket)) < 0) {
//        perror("ERROR on binding");
//        exit(1);
//    }
//
//    /* Now start listening for the clients, here process will
//       * go in sleep mode and will wait for the incoming connection
//    */
//
//    listen(sockfd,1);
//    DataReader();
//    /*clilen = sizeof(cli_addr);
//
//    // Accept actual connection from the client //
//    newsockfd = accept(sockfd, (struct sockaddr )&cli_addr, (socklen_t)&clilen);
//
//    if (newsockfd < 0) {
//        perror("ERROR on accept");
//        exit(1);
//    }
//
//*/
//
//
//}
//
//void *Sockets::getFlightSocket(void *arg) {
//
//}
//
//void Sockets::DataReader() {
//    std::cout<<"Waiting"<<endl;
//    sockaddr_in client_sock;
//    int client;
//    int client_sock_fd=accept(id,(struct sockaddr*)&client_sock,(socklen_t*)&client);
//    if(client_sock_fd<0){
//
//    }else {
//        std::cout << "hii" << endl;
//    }
//}





#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
#include "Sockets.h"

int Sockets::func( int argc, char *argv[] ) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;

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

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n",buffer);

    /* Write a response to the client */
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    return 0;
}




