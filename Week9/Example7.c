#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/*
PASSING MULTIPLE ARGUMENT 
*/

// WHEN PASSING MULTIPLE ARGUMENTS TO A CHILD THREAD, THE STANDART APPROACH IS TO GROUP
// THE ARGUMENTS WITHIN A STRUCT DECLARATION
struct Arguments
{
    int value;
    const char *second;
};
void* fonksiyon1(void*);
struct Arguments *args;

int main(){
    args = malloc(sizeof(struct Arguments));
    args->value = 149;
    args->second = "hello";
    pthread_t myThreads;
    int result = pthread_create(&myThreads, NULL, &fonksiyon1, args);
    pthread_exit(0);
}
void* fonksiyon1(void* _argumnets){
    /*CAST ARGUMENTS INTO A MEANINGFUL POINTER TYPE THAT WE CAN USE*/
    struct Arguments *args = (struct Arguments *) _argumnets;

    printf("First : %d, Second : %s \n", args->value, args->second);
    return 0;
    pthread_exit(NULL);
}