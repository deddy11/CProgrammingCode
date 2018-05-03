#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
int main()
{
    int fd;
    char myfifo[] = "/tmp/myfifo";
    char command[] = "Test apapun coba aja";
    
    char *myfifo2 = myfifo;
    char *command2 = command;

    /* create the FIFO (named pipe) */
    mkfifo(myfifo2, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo2, O_WRONLY);
    write(fd, command2, sizeof(command2));
    close(fd);

    /* remove the FIFO */
    unlink(myfifo2);

    return 0;
}