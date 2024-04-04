#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
pid_t
getpid()
getppid()
#include <unistd.h>

*/
int main(){


    pid_t pID = fork();
    //fork will return proccess id 
    if(pID==0){ // Child proccess will execute here
        printf("I am child. My proccess id is : %d and my parents proccess id is : %d \n", getpid(), getppid());
    
        //getpid()   return proccess id of the current proccess
        //getppid()  returns parent proccess id of the current proccess

        // waitid
        // waitpid
        // wait(detailed)
        // wait and exit



    }
    else if(pID>0){ // Parent proccess will execute here

        printf("i am parent. Im going to wait for my child \n. my proccess id is: %d \n", getpid());
        wait(NULL); // wait up to any child terminated its task
        printf("my child dead. So I can continue.");

    }else if(pID<0){ // Error will execute here

        printf("the system can not create a new child\n");


    }else{
        printf("an error occurd \n");
    }

    //chain proccess fan proccess geek for geeks 
    // q1 make  it one file
    // q2 make it one file
    // q4 install package (linux print proccess tree bach)
    // compress the file
    // add your name and school number



return 0 ;
}