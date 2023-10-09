#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <poll.h>
#include <sys/eventfd.h>
int main(){
    int ch;
    bool running;
    int seconds;
    struct pollfd poll_fds[1];

    poll_fds[0].fd = STDIN_FILENO;
    poll_fds[0].events = POLLIN;

    running = true;
    seconds = 0;


    initscr();


    while (running) {
        printf("%d seconds\n\r", seconds++);

        if ( poll(poll_fds, 1, 1000) < 0 ) {
            perror("Error \n");
            continue;
        }

        if (poll_fds[0].revents & POLLIN) {
            ch = getch();
            switch(ch) {
                case 'q': case 'Q':
                    running = false;
                break;
                default: ;
            }
        }
    }
    endwin();
    return 0;
}