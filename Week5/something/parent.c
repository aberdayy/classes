#include <stdio.h>
#include <unistd.h> //  exec icin gerekli
#include <sys/types.h>
#include <sys/wait.h>//wait icin gerekli
#include <stdlib.h> //exit icin gerekli


int main(){
    int i =0;
    long sum;
    int pid;
    int status, ret;


    pid_t pID = fork(); 

    if (pID == 0){
        char *args[] = {NULL};
        char *arge[] = {NULL};

        execve(args[0], args,arge);
    }else if(pID >0){
        waitpid(pID, NULL,0); // proccess ID, status arguments, option
    }

    printf("i am the parent \n");
    return 0;

}