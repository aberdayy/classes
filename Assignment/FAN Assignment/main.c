#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define NUM_CHILDREN 3

int main() {
    int pipes[NUM_CHILDREN][2];
    char *filenames[NUM_CHILDREN] = {"example1.txt", "example2.txt", "example3.txt"};
    int i, status;
    int sum;

    // pipe
    for (i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(1);
        }
    }

    for (i = 0; i < NUM_CHILDREN; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            // hata
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // cocuk
            close(pipes[i][0]);
            
            int value;
            FILE *file = fopen(filenames[i], "r");
            if (!file) {
                perror("fopen");
                exit(1);
            }
            if (fscanf(file, "%d", &value) != 1) {
                perror("fscanf");
                exit(1);
            }
            fclose(file);

            write(pipes[i][1], &value, sizeof(value));
            close(pipes[i][1]);
            exit(0);
        } else {
            // Parent
            close(pipes[i][1]);
        }
    }

    // Parent cocuku bekler
    for (i = 0; i < NUM_CHILDREN; i++) {
        int value;
        wait(&status);
        if (read(pipes[i][0], &value, sizeof(value)) == -1) {
            perror("read");
            exit(1);
        }
        sum += value;
        printf("Value from child %d: %d\n", i, value);
        close(pipes[i][0]);
    }
        printf("Total of values on childs : %d \n", sum);

    return 0;
}
