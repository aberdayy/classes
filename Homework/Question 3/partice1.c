#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
QUESTION: Create fun that a parent and three children. The parent must wait until all children exited. 
For this question use the correct function among wait, waitid and waitpid.
*/
void waitForChProc(pid_t child_pID[], int nChild){
    int status;
    while (nChild>0){
        pid_t pID = waitpid(-1, &status, 0);// wait for any child pr
        if (pID>0){
            printf("child with pID %ld exited \n",(long)pID);
            nChild--;
        }
    }
}
int main(){
    pid_t child_pID[3];
    int nChild = sizeof(child_pID)/sizeof(child_pID[0]);
    
    for (int i = 0; i < nChild; i++)
    {
        child_pID[i] = fork();// create new child pr
        if (child_pID[i]<0)
        {
            //fail
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (child_pID[i]==0)
        {
            //child pr
            printf("child %d with pid %ld running \n",i, (long)getpid());
            sleep(1+i);// simulation of work
            printf("child %d with pid %ld is done \n",i,(long)getpid());
            exit(EXIT_SUCCESS);
        }
        
    }
    //parent wait for childrebs to exit
    waitForChProc(child_pID,nChild);
    printf("parent procs exit\n");
    return 0;
}
