#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUF 1024

void delay(int milliseconds);

int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];
    int delayPeriod = 500;

    while(strcmp(buf,"stop") != 0){
        fd = open(myfifo, O_RDONLY);
        printf("fd = %d\n", fd);
        read(fd, buf, MAX_BUF);
        // printf("Received: %s\n", buf);
        system(buf);
        strcpy(buf,"");
        close(fd);
        delay(delayPeriod);
    }
    
    return 0;
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}