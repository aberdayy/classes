#include <stdio.h>
#include <unistd.h>


int main(){

    int pipefds[2];
    int returnstatus;
    int pid;
    char writemessages[2][20] = {"Hi", "hello"};
    char readmessage[20];
    returnstatus = pipe(pipefds);
    if (returnstatus==-1){
        printf("unable to create pipe \n");
        return 1;
    }
    pid = fork();
        //child

    if (pid==0)
    {
        read(pipefds[0],readmessage,sizeof(readmessage));
        printf("Child process reading from pope = message 1 is %s \n", readmessage);
        read(pipefds[0],readmessage, sizeof(readmessage));
        printf("child proccess reading from pipe = message 2 is %s \n", readmessage);

    }else{
        // parent
        printf("parent proccess writing to pipe message 1 is %s \n", writemessages[0]);
        write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
        printf("parent proccess = writing to pipe message 2 is %s \n", writemessages[1]);
        write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
    }
    


    return 0;
}