#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For sleep method

void* fonksiyon1(void*);
void* fonksiyon2(void*);

int main(){
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &fonksiyon1, NULL);
    pthread_create(&thread2, NULL, &fonksiyon2, NULL);
    printf("ana iplikteyim. Diger iplikleri bekleme konumuna geciyorum. \n");
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Ana iplikteyim digeriki yavru iplikten geri donusler oldu. Artik sureci sonlandirabilirim. \n");
    return 0;
}

void* fonksiyon1(void*){
    for (int i = 0; i < 10; i++)
    {
        printf("fonksiyon - 1 - process : %d \n", i);
        sleep(1);
    }
    return 0;
    pthread_exit(NULL);
}

void* fonksiyon2(void*){
    for (int i = 0; i < 10; i++)
    {
        printf("fonksiyon - 2 - process : %d \n", i);
        sleep(1);
    }
    return 0;
    pthread_exit(NULL);
}