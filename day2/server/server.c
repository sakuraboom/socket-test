/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   server.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:18:10 2020/07/14 二
*     > Comment     :
**********************************************************/

#include "../head.h"
#define M 1024
int main (int argc, char **argv) {
    if (argc != 2) {
        fprintf (stderr, "Error occurs in file : %s\n", argv[0]);
        exit (1);
    }
    int server_listen, sockfd;
    FILE *fp;

    if ((server_listen = socket_create (atoi (argv[1]))) < 0) {
        perror ("Error occurs in : socket_create ()");
        exit (1);
    } 

    if ((sockfd = accept (server_listen, NULL, NULL)) < 0) {
        perror ("Error occurs in : accept ()");
        exit (1);
    }
    
    if ((fp = fopen ("tmp.txt", "w")) == NULL) {
        perror ("Error occurs in : fopen ()");
        exit(1);
    }
    
    uint64_t sum, nwrite = 0;
    recv (sockfd, &sum, sizeof (sum), 0);
    printf ("%ld\n", sum);
    
    while (1) {
        if (nwrite >= sum) {
            break;
        }
        char buff[M + 5] = {0};
        int rp = recv (sockfd, buff, 1024, 0);
        if (rp <= 0) break;
        nwrite += rp;
        fwrite (buff, 1, rp, fp);
        printf ("%ld\n", nwrite);
    }
    
    fclose (fp);
    close (sockfd);
    close (server_listen);
    return 0;
}


