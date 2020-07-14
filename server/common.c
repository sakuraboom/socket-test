/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   common.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:20:25 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "../head.h"

int socket_create (int ip) {
    int sockfd;
    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) return -1;
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons (ip);
    server.sin_addr = ;
}
