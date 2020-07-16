/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   server.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:18:10 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "../head.h"
#define pthread_n 10

void *server (void *arg) {
    int server_listen = *(int *)arg;
    int sockfd;
    if ((sockfd = accept (server_listen, NULL, NULL)) < 0) {
        perror ("Error occurs in : accept ()");
        exit (1);
    }

    char buff[512] = {0};
    recv (sockfd, buff, sizeof (buff), 0);
    printf ("Recv from client : %s\n", buff);
    send (sockfd, buff, strlen (buff), 0);
    close (sockfd);
}

int main (int argc, char **argv) {
    if (argc != 2) {
        fprintf (stderr, "Error occurs in file : %s\n", argv[0]);
        exit (1);
    }
    int server_listen;
    pthread_t *pid = (pthread_t *) malloc (pthread_n * sizeof (pthread_t));

    if ((server_listen = socket_create (atoi (argv[1]))) < 0) {
        perror ("Error occurs in : socket_create ()");
        exit (1);
    } 

    for (int i = 0; i < pthread_n; i++) pthread_create (pid + i, NULL, server, &server_listen);
    for (int i = 0; i < pthread_n; i++) pthread_join (pid[i], NULL);
    close (server_listen);
    return 0;
}
