#include <stdio.h>
#include <unistd.h>


int main(){

    int pipefds1[2],pipefds2[2];
    int returnstatus1,returnstatus2;
    int pid;
    char pipe1writemessages[20] = "Hi";
    char pipe2writemessage[20] = "hello";
    char readmessage[20];
    returnstatus1 = pipe(pipefds1);

    if (returnstatus1==-1){
        printf("unable to create pipe 1\n");
        return 1;
    }
    returnstatus2 = pipe(pipefds2);
    if(returnstatus2==-1){
        printf("unable to create pipe 2\n");
        return 1;

    }
    pid = fork();
    //parent
    if (pid!=0){
        close(pipefds1[0]); // close the unwanted pipe1 read side
        close(pipefds2[1]); // close the unwated pipe2 write side
        printf("in parent : writing to pipe 1 - message us %s \n", pipe1writemessages);
        write(pipefds1[1], pipe1writemessages, sizeof(pipe1writemessages));
        read(pipefds2[0], readmessage, sizeof(readmessage));
        printf("in parent: reading from pipe 2 message is %s \n", readmessage);

    }else{
        close(pipefds1[0]); // close the unwanted pipe1 write side
        close(pipefds2[1]); // close the unwated pipe2 read side
        read(pipefds1[0], readmessage, sizeof(readmessage));
        printf("in child: reading from pipe 1 message is %s \n", readmessage);
        printf("in child: reading from pipe 2 message is %s \n", pipe2writemessage);
        write(pipefds2[1],pipe2writemessage, sizeof(pipe2writemessage));

    }
        
   
   

    return 0;
}