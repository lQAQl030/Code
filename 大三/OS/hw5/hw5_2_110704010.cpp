#include<bits/stdc++.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

pid_t pid;

int main(){
    //Input pid generate from test2.c
    cout << "Input Heathcliff's PID: ";
    cin >> pid;

    //Create shared memory
    const char* shm_name = "/hw5_shm";
    const int shm_size = 0xC8763;
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, shm_size);
    void* shm_ptr = mmap(0, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    //Set our skill by observing pattern of test2.c
    int length = snprintf(NULL, 0, "%d", pid);
    char pid_str[length + 1];
    snprintf(pid_str, sizeof(pid_str), "%d", pid);
    for (int skill = 0; skill < length; skill++)
        for (int i = skill; i < 0xC8763; i+=length)
            *((char*)shm_ptr + i) = pid_str[skill];
    

    //Send singal
    kill(pid, SIGUSR1);
    cout << "SIGUSR1 signal was sent successfully." << endl;
    sleep(1);

    //Release shared memory
    munmap(0, shm_size);
    close(shm_fd);
    shm_unlink(shm_name);

    return 0;
}