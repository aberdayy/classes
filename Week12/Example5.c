/*
MUTEXES DEADDLOCK 

*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int globalvar1 = 5;
int globalvar2 =4;
pthread_mutex_t mutex1, mutex2;
void *function1(void *){
    printf("hello  from thread 1 \n");

    pthread_mutex_lock(&mutex1);
    printf("Thread 1 lock the globalvar1 \n");
    globalvar1++;
    sleep(5);

    pthread_mutex_lock(&mutex2);
    printf("Thread 1 lock the globalvar 2 \n");
    globalvar2++;
    sleep(5);
    printf("thread 1 relesae the globalvar1 \n");
    pthread_mutex_unlock(&mutex1);
    printf("thread 1  relese the global var 1 \n");
    pthread_mutex_unlock(&mutex2);
    pthread_exit(NULL);
}
void *function1(void *){
    printf("hello  from thread 2 \n");

    pthread_mutex_lock(&mutex2);
    printf("Thread 2 lock the globalvar2 \n");
    globalvar2++;
    sleep(5);

    pthread_mutex_lock(&mutex1);
    printf("Thread 2 lock the globalvar 1 \n");
    globalvar1++;
    sleep(5);
    printf("thread 2 relesae the globalvar2 \n");
    pthread_mutex_unlock(&mutex1);
    printf("thread 2  relese the global var 1 \n");
    pthread_mutex_unlock(&mutex1);
    pthread_exit(NULL);
}
int main(void){
    pthread_t threads[2];
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    printf("Hello from the main \n");
    int result1 = pthread_create(&threads[0], NULL, function1, NULL);
    int result2 = pthread_create(&threads[1], NULL, function1, NULL); 
    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    pthread_exit(0);
}
