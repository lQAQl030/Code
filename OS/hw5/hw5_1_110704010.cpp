#include<bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(){
    mkfifo("./hw5_read.fifo", 0777);
    mkfifo("./hw5_write.fifo", 0777);

    int fd_read = open("./hw5_read.fifo", O_RDONLY);
    int fd_write = open("./hw5_write.fifo", O_WRONLY);

    while(true){
        //Read char from fifo
        char c = '0';
        string str = "";
        while(read(fd_read, &c, 1)){
            if(c == '\n') break;
            str += c;
        }

        //Sort and check end
        cout << "Received: " << str << endl;
        if(str == "Well done!") break;
        sort(str.begin(), str.end());
        cout << "Answer  : " << str << endl << endl;

        //Write char to fifo
        write(fd_write, str.data(), str.length());
        c = '\n';
        write(fd_write, &c, 1);

        //Wait 1 sec
        sleep(1);
    }

    close(fd_read);
    close(fd_write);
    unlink("./hw5_write.fifo");
    cout << "hw5_write.fifo deleted" << endl;
    unlink("./hw5_read.fifo");
    cout << "hw5_read.fifo  deleted" << endl;

    return 0;
}