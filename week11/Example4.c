/*
Ortak Degisken kullanimi
*/
#include <stdio.h>
#include <pthread.h>

void* function1(int *);
int myVariable = 1;
int main(){
    pthread_t thread1;
    pthread_create(&thread1,NULL, &function1, &myVariable);
    pthread_join(thread1, NULL);
    for (int x = 0; x<10;  x++){
        printf("ana iplik: %d \n", myVariable);
        myVariable++;
    }
    return 0;
}
void* function1 (int* number){
    for(int x = 0; x<10; x++){
        printf("yeni iplik: %d \n", *number);
        (*number)++;
    }
    return 0;
    pthread_exit(NULL);
}