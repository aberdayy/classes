#include <stdio.h>
#include <pthread.h>
/*
PASSING SINGLE ARGUMENT 
*/
void * funksiyon(void*);

int main(){
    pthread_t thread;
    int veri = 123;

    pthread_create(&thread, NULL, &funksiyon, (void*)veri);
    pthread_join(thread, NULL);
    pthread_exit(NULL);
    return 0;
}
void * funksiyon(void* GelenVeri){
    int sayi = (int) GelenVeri; /* TYPE CASTING*/ 
    printf("BEN YENI IPLIK. DISARIDAN GELEN VERI : %d \n", sayi);
    return 0;
    pthread_exit;(NULL);
}