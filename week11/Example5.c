#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include <unistd.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif
void* WhoIAm(void *threadID);
int main(){
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i<4; i++){
        pthread_create(&threads[i], NULL, &WhoIAm, (void *)i);
    }
    pthread_exit(0);

}
void* WhoIAm(void *threadID){
    long tid=(long)threadID;
    printf("Hello! thread %1d, pthread ID - %1u \n", tid,pthread_self());
    pthread_exit(NULL);
}