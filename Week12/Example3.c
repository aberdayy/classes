#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h> // SLEEP ICIN 

pthread_mutex_t lock;

typedef struct 
{
    char* p;
    char* q;

}ThreadArgs;


void* Test(void* arg){
    ThreadArgs* args = (ThreadArgs*)arg;
    pthread_mutex_lock(&lock);
    printf("%s... \n",args-> p);
    sleep(5);
    printf("%s... \n", args-> q);
    sleep(5);
    pthread_mutex_unlock(&lock);
}


    ThreadArgs args1  = {"1st thread initiated", "1st thread"};
    ThreadArgs args2  = {"2st thread initiated", "2st thread"};


int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &Test, (void*)&args1); 
    pthread_create(&t2, NULL, &Test, (void*)&args2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    exit(0);
}