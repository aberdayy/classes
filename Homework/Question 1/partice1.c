#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <asm-generic/siginfo.h>
#include <linux/wait.h>

/*
QUESTION : 
                    Compares wait, waitid and waitpid in details

*/


// WIFEXISTED =>The status field that was filled in by the wait or waitpid function. (ibm.com/docs)
int main(){
    pid_t pID = fork();
    int status;
    if(pID==0){ // Child proccess will execute here
        printf("I am child. My proccess id is : %d and my parents proccess id is : %d \n", getpid(), getppid());
    }
    else if(pID>0){ // Parent proccess will execute here
        printf("i am parent. Im going to wait for my child \n. my proccess id is: %d \n", getpid());
        wait(NULL); // wait up to any child terminated its task
        printf("my child dead. So I can continue.");

/*
    // Wait
    if(wait(&status) ==-1){
        perror("wait");
    }else{
        printf("wait: Child proccess terminated \n");
        if (WIFEXITED(status))
        {
            printf("Child exited with status %d \n",WEXITSTATUS(status));
        }
        
    }
*/



    // waitpid
    /*
    if (waitpid(pID, &status, 0) == -1)
    {
        perror("waitpid");
    }else
    {
        printf("waitpid: child proccess terminated \n");
        if (WIFEXITED(status))
        {
            printf("Child exited with status %d \n", WEXITSTATUS(status));
        }
    }
    */




   // waitid
   /*
   siginfo_t infop;
   if (waitid(P_PID, pID, &infop, WEXITED) !=0)
   {
    perror("waitid");
   }else
   {
    printf("waitid: Child proccess terminated \n");
    if (infop.si_code == CLD_EXITED)
    {
        printf("Child exited with status %d \n", infop.si_status);
    }
    
   }
   */

  
   
    }else if(pID<0){ // Error will execute here
        printf("the system can not create a new child\n");
    }else{
        printf("an error occurd \n");
    }
return 0 ;
}