
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* doSomeThing(void *args){
    // BU ORNEKTE MUTEXLERI KALDIRIP SONUCUN NASIL DEGISTIGINI  GOZLEMLEYINIZ

    pthread_mutex_lock(&lock);
    unsigned long i = 0;
    counter+= 1;
    printf("\n Job %d started \n", counter);
    for(i=0; i<(0XFFFFFFFF); i++);
    printf("\n Job %d finished \n", counter);
    pthread_mutex_unlock(&lock); // RELEASE THE MUTEX LOCK
    return NULL;
}
int main(void){
    int i = 0;
    int err;
    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("\n mutex init failed \n");
        return 1;

    }
    while(i<2){
        err = pthread_create(&tid [i], NULL, &doSomeThing,NULL);
        if(err != 0){
            printf("\n cant create thread; [%s]");
        }
        i++;

    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
    
}