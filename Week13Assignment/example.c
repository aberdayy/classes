#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define dosya_boyutu 100

int islemYuzdesi = 0;
pthread_mutex_t lock;

void* download(void *arg) {
    while (islemYuzdesi < dosya_boyutu) {
        pthread_mutex_lock(&lock);  // mutex lock
        islemYuzdesi++;                  // indirme islemi kontrolcusu
        printf("Indiriliyor: %d%%\n", islemYuzdesi);
        pthread_mutex_unlock(&lock); // unlock
        sleep(1);                    // Zamanlayici
    }
    return NULL;
}

void* yazdir(void *arg) {
    int last_printed = 0;
    while (last_printed < dosya_boyutu) {
        pthread_mutex_lock(&lock);  // mutex lock
        if (last_printed != islemYuzdesi) {
            printf("yazdirildi: %d%% \n", islemYuzdesi);
            last_printed = islemYuzdesi;
        }
        pthread_mutex_unlock(&lock); // unlock
        //sleep(1); Bu sekilde yapinca yazdirma senkronu bozuluyor
        usleep(100000); 
    }
    return NULL;
}
int main() {
    pthread_t t1, t2; // thread tanimlama 
    int res;

    // mutex tanimlama
    pthread_mutex_init(&lock, NULL);

    res = pthread_create(&t1, NULL, download, NULL);
    if (res != 0) {
        perror("Thread olusmadi");
        return 1;
    }

    res = pthread_create(&t2, NULL, yazdir, NULL);
    if (res != 0) {
        perror("Thread olusmadi");
        return 1;
    }

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);


    return 0;
}