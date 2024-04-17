#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct args
{
    int a;
    int b;
};
struct results{
    int sum;
    int difference;
    int product;
    int quotient;
    int modulus;
};
void *calculator(void *_args){
    struct args *args = (struct agrs *)_args;
    struct results *results = calloc(sizeof(struct results),1);
    results->sum = args ->a + args-> b;
    results-> difference = args->a + args->b;
    results-> product = args->a * args->b;
    results-> quotient = args->a / args->b;
    results-> modulus = args->a % args->b;
    free(args);
    pthread_exit(results);
}

int main(){
    pthread_t child[5];
    struct args *args[5] = {NULL, NULL,NULL,NULL,NULL};
    for(int i =0; i<5;i++){
        args[i]=calloc(sizeof(struct args),1);
        args[i]->a = i+1;
        args[i]->b = (i+1)*(i+1);
        pthread_create(&child[i],NULL, calculator, args[i]);
    }
struct results *results[5];
for(int i = 0; i<5; i++){
    pthread_join(child[i], (void **)&results[i]);

        printf("calculator (%d, %2d)==>",i+1,(i+1)*(i+1));
        printf("+:%3d;    ", results[i]->sum);
        printf("-:%3d;    ", results[i]->difference);
        printf("*:%3d;    ", results[i]->product);
        printf("/:%3d;    ", results[i]->quotient);
        printf("%%:%3d;    ", results[i]->modulus);
        free(results[i]);

}
pthread_exit(0);
}