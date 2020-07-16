/**********************************************************
*     > Do Androids Dream of Electric Sheep? 
*     > File Name   :   add_thread_multi.c
*     > Author      :   spike
*     > Email       :   Gehirn@yeah.net
*     > Create time :   CST 15:59:00 2020/07/16 四
*     > Comment     :   多线程加法
**********************************************************/

#include "../head.h"
#define pthread_n 5

int sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add (void *arg) {
    while (1) {
        
        pthread_mutex_lock (&mutex);
        if (sum < 1000) {
            sum ++;
            printf ("Now is in pthread : %ld, sum = %d\n", pthread_self (), sum);
        } else {
            pthread_mutex_unlock (&mutex);
            break;
        }
        pthread_mutex_unlock (&mutex);
    }

}

int main (int argc, char **argv) {
    
    pthread_t *pid = (pthread_t *) malloc (pthread_n * sizeof (pthread_t));
    for (int i = 0; i < pthread_n; i++) pthread_create (pid + i, NULL, add, NULL);
    for (int i = 0; i < pthread_n; i++) pthread_join (pid[i], NULL);
    
    printf ("result : %d\n", sum);
    return 0;
    
}
