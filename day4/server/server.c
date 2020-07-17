/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   server.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:18:10 2020/07/14 二
*     > Comment     :   I/O多路复用实现并发
**********************************************************/

#include "../head.h"
#define client_n 100

int main (int argc, char **argv) {
    if (argc != 2) {
        fprintf (stderr, "Error occurs in file : %s\n", argv[0]);
        exit (1);
    }
    int server_listen;

    if ((server_listen = socket_create (atoi (argv[1]))) < 0) {
        perror ("Error occurs in : socket_create ()");
        exit (1);
    } 
    
    int clients[client_n], sockfd;
    int max_fd = server_listen;
    fd_set rfds, wfds, efds;

    for (int i = 0; i < client_n; i++) clients[i] = -1;


    while (1) {
        FD_ZERO (&rfds);
        FD_ZERO (&wfds);
        FD_ZERO (&efds);
        FD_SET (server_listen, &rfds);

        for (int i = 0; i < client_n; i++) {
            if (clients[i] == server_listen) continue;
            if (clients[i] > 0) {
                if (clients[i] > max_fd) max_fd = clients[i];    
                FD_SET (clients[i], &rfds);
            } 
        }

        int ret = 0;
        if ((ret = select (max_fd +1,&rfds,NULL, NULL, NULL)) < 0) {
            perror ("select ()");
            exit (1);
        }

        if (FD_ISSET (server_listen, &rfds)) {
            struct sockaddr_in client;
            socklen_t len = sizeof (client);
            if ((sockfd = accept (server_listen, (struct sockaddr *)&client, &len)) < 0) {
                perror ("accept ()");
                exit (1);
            }
            printf ("Login : %s<%d>\n", inet_ntoa (client.sin_addr), ntohs (client.sin_port));
            
            if (sockfd > client_n) {
                fprintf (stderr, "Too many clients !\n");
                close (sockfd);
            } else {
                if (clients[sockfd] == -1) {
                    clients[sockfd] = sockfd; 
                }
            }
        }

        for (int i = 0; i <= max_fd; i++) {
            if (clients[i] == server_listen || clients[i] < 0) continue;
            if (FD_ISSET (clients[i], &rfds)) {
                char buff[512] = {0};
                int len = recv (clients[i], buff, sizeof (buff), 0);
                if (len <= 0) {
                    close (clients[i]);
                    clients[i] = -1;
                }
                printf ("Recv from client : %s\n", buff);
                send (clients[i], buff, strlen (buff), 0);
            }
        }
    }

    /* close (server_listen); */
    return 0;
}
