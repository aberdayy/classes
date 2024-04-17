#include <stdio.h>
#include <unistd.h> // header file for sleep()
#include <pthread.h>
void* function1(void*);
void* function2(void*);

int main(){
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &function1, NULL);
    pthread_create(&thread2, NULL, &function2, NULL);
    for (int x=0; x<5; x++){
        printf("Main Thread \n");
        sleep(1);
    }
    // return 0;    It means the process ended. So it is not wait for detached threads
    // pthread_exit(0)  it means the main thread finished but not the proccess so wait for the others.
    pthread_exit(0);
}
void* function1(void*){
    pthread_detach(pthread_self);
    for(int x=0; x<5; x++){
        printf("Function - 1 - \n");
        sleep(1);
    }
    return 0;
    pthread_exit(NULL);
}
void* function2(void*){
    pthread_detach(pthread_self);
    for(int x=0; x<5; x++){
        printf("Function - 2 - \n");
        sleep(1);
    }
    return 0;
    pthread_exit(NULL);
}