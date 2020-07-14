/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   client.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:38:59 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "../head.h"

struct UserInfo {
    char name[50];
    char id[50];
};

int main (int argc, char **argv) {
    if (argc != 3) {
        fprintf (stderr, "Error occurs in file : %s \n", argv[0]);
        exit (1);
    } 

    int port, sockfd;
    char ip[20] = {0};
    strcpy (ip, argv[1]);
    port = atoi (argv[2]);

    if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
        perror ("socket()\n");
        exit(1);
    }

    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons (port);
    client.sin_addr.s_addr = inet_addr (ip);

    if ((connect (sockfd, (struct sockaddr *)&client, sizeof (client))) < 0) {
        perror ("connect() error\n");
        exit (1);
    }

        /* char buff[512] = {0}; */
        /* recv (sockfd, buff, sizeof(buff), 0); */
        /* int ant = (int)(buff[0]); */
        /* printf ("Recv from Server : %d\n", ant); */
        /* close (sockfd); */

    while (1) {
        int flag= 0, ant;
        char buff[512] = {0};
        recv (sockfd, buff, sizeof(buff), 0);
        ant = (int)(buff[0]);
        
        printf ("Recv from Server : %d\n", ant);
        switch (ant) {
            case 1 : {
                         strcpy (buff, "2018302050084");
                         send (sockfd, buff, strlen (buff), 0);
                         break;          
                     }
            case 2 : {
                         strcpy (buff, "杨猛");
                         send (sockfd, buff, strlen (buff), 0);
                         break;
                     }

            case 3 : {
                        
                         struct UserInfo info;
                         strcpy (info.name, "杨猛");
                         strcpy (info.id, "2018302050084");
                         send (sockfd, (char *)&info, sizeof (UserInfo), 0);
                         break;
                     }
            case 4 : {
                         flag = 1;
                         close (sockfd);
                         break;
                     }
        }
        if (flag) break;
    }
    return 0;
}


