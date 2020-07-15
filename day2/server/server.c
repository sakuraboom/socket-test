/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   server.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:18:10 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "../head.h"

int main (int argc, char **argv) {
    if (argc != 2) {
        fprintf (stderr, "Error occurs in file : %s\n", argv[0]);
        exit (1);
    }
    int server_listen, sockfd;
    
    if ((server_listen = socket_create (atoi (argv[1]))) < 0) {
        perror ("Error occurs in : socket_create ()");
        exit (1);
    } 

    if ((sockfd = accept (server_listen, NULL, NULL)) < 0) {
        perror ("Error occurs in : accept ()");
        exit (1);
    }

    char buff[512] = {0};
    recv (sockfd, buff, sizeof (buff), 0);
    printf ("Recv from client : %s\n", buff);
    /* send (sockfd, buff, strlen (buff), 0); */
    close (sockfd);
    close (server_listen);
    return 0;
}
