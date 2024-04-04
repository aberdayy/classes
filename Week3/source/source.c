#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


/*
pid_t
getpid()
getppid()
#include <unistd.h>

*/
int main(){


    pid_t myproccessID = fork();
    //fork will return proccess id 
    if(myproccessID==0){
        printf("I am child \n");
    }
    else if(myproccessID>0){

        printf("i am parent \n");

    }else{
        printf("an error occurd \n");
    }

return 0 ;
}