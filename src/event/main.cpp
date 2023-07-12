#include <iostream>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

const int MAX_EVENTS = 10;

int main()
{
    int uartfd =open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (uartfd == -1)
    {
        perror("无法打开串口");
        return -1;
    }
    struct termios options;
    tcgetattr(uartfd, &options); 
    cfsetispeed(&options, B9600); 
    cfsetospeed(&options, B9600);
    options.c_cflag |= (CLOCAL | CREAD); 
    options.c_cflag &= ~PARENB; 
    options.c_cflag &= ~CSTOPB; 
    options.c_cflag &= ~CSIZE; 
    options.c_cflag |= CS8; 
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_iflag &= ~(IXON | IXOFF | IXANY); 
    options.c_oflag &= ~OPOST; 
    tcsetattr(uartfd, TCSANOW, &options); 

    int epoll_fd = epoll_create1(EPOLL_CLOEXEC);
    if (epoll_fd == -1)
    {
        std::cout << "Failed to create epoll instance." << std::endl;
        return 1;
    }

    struct epoll_event event;
    event.data.fd = uartfd;
    event.events = EPOLLIN;

    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, uartfd, &event) == -1)
    {
        std::cout << "Failed 2 " << std::endl;
        close(epoll_fd);
        return 1;
    }
    struct epoll_event events[MAX_EVENTS];
    for(;;)
    {
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_events == -1)
        {
            std::cout << "Failed to wait for events." << std::endl;
            close(epoll_fd);
            return 1;
        }

        for (int i = 0; i < num_events; i++)
        {
            if (events[i].events == EPOLLIN && (events[i].data.fd == uartfd))
            {
                //std::cout << events[i].data.u64 << std::endl;
                char buffer[256];
                memset(buffer,0,256);
                int num_bytes = read(uartfd, buffer, sizeof(buffer));
                std::cout << "Epool Read STDIN: " << buffer;
                // Handle file write event here
                break;
            }
        }
    }
    close(epoll_fd);

    return 0;
}