/**
 & <= check what this does on a function with a parameter
 ex: func1(&v1,&v2);

 passing with referance


*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct numbers
{
    int a;
    int b;
    int sum;
};
void sum_thread(void *_args){
    struct numbers *args = (struct numbers*) _args;
    args->sum = args->a +args->b;
    pthread_exit(NULL);

}
int main(){
    struct numbers *args = calloc(sizeof(struct numbers),1);
    args->a = 5;
    args->b=6;
    pthread_t child;
    int result = pthread_create(&child, NULL, sum_thread, args);
    pthread_join(child, NULL);
    printf("%d + %d = %d \n", args-> a, args->b, args->sum);
    free(args);
    args = NULL;
    pthread_exit(0);
}