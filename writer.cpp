#include <iostream>
// #include <fcntl.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <unistd.h>
#include <string>

using namespace std;
int main()
{
    // int fd;
    // char myfifo[] = "/tmp/UAVtemp1";
    // char command[] = "ls";
    
    // char *myfifo2 = myfifo;
    // char *command2 = command;

    // /* create the FIFO (named pipe) */
    // mkfifo(myfifo2, 0666);

    // /* write "Hi" to the FIFO */
    // fd = open(myfifo2, O_WRONLY);
    // write(fd, command2, sizeof(command2));
    // close(fd);

    // /* remove the FIFO */
    // unlink(myfifo2);
    int i = 1;
    string systemCommand = "gnome-terminal -x sh -c 'cd ~/Deddy/QGroundProject/CProgrammingCode; ./executeUAV; exec sleep 2; exit'";

    systemCommand.insert(81,to_string(i));
    cout << systemCommand << endl;

    return 0;
}