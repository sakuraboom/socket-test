/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   test.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 23:58:21 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "head.h"

int main (int argc, char **argv) {
    if (argc != 3) {
        fprintf (stderr, "Error in client : *argv[] ( filename : %s )", argv[0]);
        exit (1);
    }
    char ip[20];
    int port = atoi (argv[2]);
    int sockfd;
    struct sockaddr_in client;
    strcpy (ip, argv[1]);
    

    client.sin_family = AF_INET;
    client.sin_port = port;
    client.sin_addr.s_addr = inet_addr (ip);
    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("Error socket");
        exit (1);
    }

    if ((connect (sockfd, (struct sockaddr *)&client, sizeof (client))) < 0) {
        perror ("Error connet");
        exit (1);
    }
    
    char buff[512] = {0};
    scanf ("%s", buff);
    send (sockfd, buff, strlen (buff), 0);
    memset (buff, 0, sizeof (buff));
    recv (sockfd, buff, sizeof (buff), 0);
    printf ("Recv from server : %s\n", buff);
    close (sockfd);
    return 0;
}


