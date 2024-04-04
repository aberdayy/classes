#include <stdio.h>
#include <pthread.h>
/*
CHECK THREAD ID
*/



void* fonksiyon1(void *);

int main(){
    pthread_t mainThread, newThread;

    pthread_create(&newThread, NULL, &fonksiyon1, NULL);
    printf("Main thread ID : %d \n", pthread_self());
    pthread_join(newThread, NULL); 
    /* 
    Join yapmaz isek ve ana iplik calismasini bitirir ise return 0 ile, 
    yeni ipligimiz calismadan proccess sonlandirilir.
    */
   return 0;
}
void* fonksiyon1(void *){
    printf("New thread id : %d \n", pthread_self());
    return 0;
    pthread_exit(NULL);
}