#include <stdio.h>
#include <pthread.h>
/*
CREATE AND CHECK THREAD
*/



void* fonksiyon1(void *);

int main(){
    pthread_t iplik1;
    int olusturulmus_mu = pthread_create(&iplik1, NULL, &fonksiyon1, NULL);
    if (olusturulmus_mu==0){
        printf("Thread have been created succesfully \n");
    }else{
        printf("An error have been occured!");
    }

    pthread_join(iplik1, NULL); /* Join yapmaz isek ve ana iplik calismasini bitirir ise return 0 ile, 
    yeni ipligimiz calismadan proccess sonlandirilir.
    */
   return 0;
}
void* fonksiyon1(void *){
    printf("Hello from new thread! \n");
    return 0;
    pthread_exit(NULL);
}