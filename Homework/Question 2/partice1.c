#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
QUESTION 2: Create a chain so that each parent must wait with its child.
 Use the correct function among wait.
 Waitid and waitpid. Each parent should wait with its childid.
*/
int main(){
    pid_t pID;
    int NP = 3;
    int i;

    for(i=0; i<NP; i++){
        pID = fork();
        
        if (pID == 0)
        {
            // Child 
            printf("Child pID = %d, parent pID = %d \n", getpid(),getppid());
            if (i<NP-1)
            {
                continue; // keep forking until theres no child
            }else
            {
                exit(EXIT_SUCCESS);// last child exit
            }
        }else{
            //parent
            int status;
            waitpid(pID,&status,0); //Wait for child to finish
            printf("Child with pID : %d is done\n",pID);
            break;// the make sure theres is only one child per parent.
        }
        
        if (pID>0)
        {
            printf("parent pID => %d exiting. \n", getpid());
        }
        
        
        if (pID <0)
        {
            //failed
            perror("fork");
            exit(EXIT_FAILURE);
        }



        
    }

   
   

    //chain proccess fan proccess geek for geeks 
    // q1 make  it one file
    // q2 make it one file
    // q4 install package (linux print proccess tree bach)
    // compress the file
    // add your name and school number



return 0 ;
}