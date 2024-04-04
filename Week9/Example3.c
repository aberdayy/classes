#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

/*
COMPARE THREADS
*/

void* fonksiyon1(void *);

int main(){
    pthread_t mainThread, newThread;
    pthread_create(&newThread, NULL, &fonksiyon1, NULL);
    pthread_join(newThread, NULL); 

    bool ayniMi = pthread_equal(mainThread, newThread);

    if (ayniMi){
        printf("her iki iplikde aynidir. \n");
    }else{
        printf("iki farkli iplik soz konusu \n");
    }
    return 0;

}
void* fonksiyon1(void *){
    return 0;
    pthread_exit(NULL);
}