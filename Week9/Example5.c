#include <stdio.h>
#include <pthread.h>
/*
SWITCHING BETWEEN THREADS
*/
void * func(void*);

int main(){
    pthread_t ptid;
    pthread_create(&ptid, NULL, &func, NULL);
    printf("Henuz main fonksiyonuna iliskili thread icerisindeyim \n");
    pthread_join(ptid, NULL);
    printf("main e geri dondum \n");
    pthread_exit(NULL);
    return 0;
}
void * func(void* arg){
    printf("olusturulmus threaddeyim \n");
    return 0;
    pthread_exit;(NULL);
}