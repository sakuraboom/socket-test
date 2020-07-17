/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   test.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:07:12 2020/07/17 五
*     > Comment     :
**********************************************************/

#include "head.h"

int recv_and_print(int fd) {
    char buff[512] = {0};
    int ret = recv(fd, buff, sizeof(buff), 0);
    if (ret <= 0) {
        close(fd);
        return -1;
    }
    printf("%s", buff);
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port!\n", argv[0]);
        exit(1);
    }
    char ip[20] = {0};
    int port, fd, stu_port;
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()");
        exit(1);
    }
    if (recv_and_print(fd) < 0) exit(1);
    scanf("%d", &stu_port);
    send(fd, &stu_port, sizeof(int), 0);
    if (recv_and_print(fd) < 0) exit(1);
    if (recv_and_print(fd) < 0) exit(1);
    if (recv_and_print(fd) < 0) exit(1);
    return 0;
}

