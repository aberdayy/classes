/*Filename : fifoclient*/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "MYFIFO"
int main(){
    int fd;
    int end_proccess;
    int stringlen;
    char readbuf[80];
    char end_str[5];
    printf("FIFO client : send message, infenitly");
    fd = open(FIFO_FILE,O_CREAT, O_WRONLY);
    strcpy(end_str, "end");
    while (1)
    {
        printf("something");
        fgets(readbuf,sizeof(readbuf), stdin);
        stringlen=strlen(readbuf);
        readbuf[stringlen = 1]= "0";
        end_proccess=strcmp(readbuf, end_str);
        //printf("end priccess is %d \n", end process);
        if(end_proccess != 0){
            write(fd, readbuf, strlen(readbuf));
            printf("sent string %s end string length is %d",readbuf, (int)strlen(readbuf));
        
        }else{
            write(fd,readbuf, strlen(readbuf));
        }

    }
    

}