#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t count_mutex;
long long count;
void increment_count(){//Ensure an atomic update of shared variale
    pthread_mutex_lock(&count_mutex);
    count = count +1;
    pthread_mutex_unlock(&count_mutex);

}
void decrement_count(){
    pthread_mutex_lock(&count_mutex);
    count = count -1;
    pthread_mutex_unlock(&count_mutex);
}

long long get_count(){ // guarantea that the 64 bit quantity count is read atomaticlly on a 32 bit architecture
    long long c;
    pthread_mutex_lock(&count_mutex);
    c = count;
    pthread_mutex_unlock(&count_mutex);
    return (c);

}

int main(){
    pthread_t thread[2];
    pthread_mutex_init(&count_mutex, NULL);
    int result1 = pthread_create(&thread[0], NULL,increment_count, &mutex);
    //print with get count
    int result2 = pthread_create(&thread[1], NULL, decrement_count, &mutex);
    //print with get count
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_exit(0);
}