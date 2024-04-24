/*
MUTEXES
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int globalvar = 5;


void *increment(void *args){
    pthread_mutex_t *mutex = (pthread_mutex_t *)args;
    pthread_mutex_lock(mutex);
    globalvar++;
    pthread_mutex_unlock(mutex);
    pthread_exit(NULL);

}
int main(void){
    pthread_t threads[2]; 
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);
    int result1=pthread_create(&threads[0], NULL, increment, &mutex);
    int result2=pthread_create(&threads[1], NULL, increment, &mutex);
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);

    pthread_exit(0);
}