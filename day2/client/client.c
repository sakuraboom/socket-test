/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   client.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 14:35:16 2020/07/15 三
*     > Comment     :
**********************************************************/

#include "../head.h"
#define M 1024

int main (int argc, char **argv) {
    if (argc != 3) {
        fprintf (stderr, "Error occurs in ip port, file : %s\n", argv[0]);
        exit (1);
    }

    int port, sockfd;
    char ip[20];
    strcpy (ip, argv[1]);
    port = atoi (argv[2]);
    
    if ((sockfd = socket_connect (ip, port)) < 0) {
        perror ("socket_connect ()");
        exit (1);
    }

    char buff[M] = "hello";
    send (sockfd, buff, strlen (buff), 0);
    close (sockfd);
    return 0;
}




