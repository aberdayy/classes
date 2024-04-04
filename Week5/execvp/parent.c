#include <stdio.h>
#include <unistd.h> //  exec icin gerekli
#include <sys/types.h>
#include <sys/wait.h>//wait icin gerekli
#include <stdlib.h> //exit icin gerekli


int main(){

    pid_t pID = fork(); 

    if (pID == 0){
        char *args[] = {"./child", NULL};
        execvp(args[0], args);
    }else if(pID >0){
        waitpid(pID, NULL,0); // proccess ID, status arguments, option
    }

    printf("i am the parent \n");
    return 0;

}