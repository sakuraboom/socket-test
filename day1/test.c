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
    strcpy (ip, argv[1]);

    return 0;
}
