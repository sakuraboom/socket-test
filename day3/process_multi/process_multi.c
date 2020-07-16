/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   process_multi.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:05:49 2020/07/16 四
*     > Comment     :   多进程实现commit参数识别
**********************************************************/

#include "../head.h"
#define M 512

int main (int argc, char **argv) {
    
    
    char msg[M] = {0};
    int opt, flag = 0;
    while ((opt = getopt (argc, argv, "m:")) != -1) {
        switch (opt) {
            case 'm' : {
                           strcpy (msg, optarg);
                           flag = 1;
                           break;
                       }
            default : {
                          exit (1);
                      }
        }
    }
    
    if (flag) {
        if (strlen (msg)) {
            printf ("Commit message : %s\n", msg);
        } else {
            fprintf (stderr, "Error : Miss commit message\n");
            exit (1);
        }
    } else {
        pid_t pid = fork ();
        if (pid == 0) {
            char cmd[M] = "file=\"tmp.txt\";if [ -e $file ];then rm $file; fi"; 
            system (cmd);

            execlp ("vim", "vim", "tmp.txt", 0);
        } else {
            int status;
            wait (&status);
            system ("cat tmp.txt");
        }
    }

    return 0;
}
