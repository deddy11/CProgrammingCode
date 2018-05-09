#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <sys/stat.h>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF 1024

using namespace std;

void delay(int milliseconds);

int main()
{
    int fd;
    char myfifo[] = "/tmp/UAVtemp";
    char *myfifo2 = myfifo;
    char check[MAX_BUF];
    char buf[MAX_BUF];
    int delayPeriod = 500;

    while(strcmp(buf,"close") != 0){
        fd = open(myfifo, O_RDONLY);
        // cout << "fd = " << fd << endl;
        
        // printf("Received: %s\n", buf);
        if(fd != -1) {
            read(fd, buf, MAX_BUF);
            if(strcmp(buf,"close") != 0) {
                system(buf);
                strcpy(buf,"");
            }

        }
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