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
    FILE *fp;
    strcpy (ip, argv[1]);
    port = atoi (argv[2]);
    
    if ((sockfd = socket_connect (ip, port)) < 0) {
        perror ("socket_connect ()\n");
        exit (1);
    }
        
    if ((fp = fopen ("../server/tmp.txt", "r")) == NULL) {
        perror ("fopen ()\n");
        exit (1);
    }

    size_t size;
    char buff[M + 5] = {0};
    while ((size = fread (buff, 1, 1024, fp))) {
        send (sockfd, buff, size, 0);
        printf ("%s\n", buff);
        bzero (buff, sizeof (buff));
    }

    fclose (fp);
    close (sockfd);
    return 0;
}




