/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   common.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:20:25 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "../head.h"
#define print_error(a, b, c) { \
    if ((a) < (b)) {  \
        perror (#c);  \
        return -1; \
    } \
}


int socket_create (int ip) {
    int sockfd;
    print_error((sockfd = socket (AF_INET, SOCK_STREAM, 0)), 0, socket())
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons (ip);
    server.sin_addr.s_addr = INADDR_ANY;//htonl (INADDR_ANY);
    print_error (bind (sockfd, (struct sockaddr *)&server, sizeof (server)), 0, bind())
    print_error (listen (sockfd, 10), 0, listen())
    return sockfd;
}

int socket_connect (char *ip, int port) {
    int sockfd;
    print_error (sockfd = socket (AF_INET, SOCK_STREAM, 0), 0, socket())
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons (port);
    client.sin_addr.s_addr = inet_addr (ip);
    print_error (connect (sockfd, (struct sockaddr *)&client, sizeof (client)), 0, connet ())
    return sockfd;
}




