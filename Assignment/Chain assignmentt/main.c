#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pipefds[2];
    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    const char *filenames[] = {"example1.txt", "example2.txt", "example3.txt"};
    int num_files = sizeof(filenames) / sizeof(filenames[0]);

    for (int i = 0; i < num_files; ++i) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // cocuk 
            close(pipefds[0]); 
            
            FILE *file = fopen(filenames[i], "r");
            if (file == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }

            int value;
            if (fscanf(file, "%d", &value) != 1) {
                perror("fscanf");
                exit(EXIT_FAILURE);
            }
            fclose(file);

            write(pipefds[1], &value, sizeof(value));
            close(pipefds[1]); // bitti

            exit(EXIT_SUCCESS);
        }
    }

    close(pipefds[1]); 

    int sum = 0;
    for (int i = 0; i < num_files; ++i) {
        int status;
        wait(&status); 

        if (WIFEXITED(status)) {
            int value;
            if (read(pipefds[0], &value, sizeof(value)) > 0) {
                sum += value;
            }
        }
    }

    printf("Total of values on childs : %d \n", sum);
    close(pipefds[0]); // okuma bitti

    return EXIT_SUCCESS;
}
