#include <stdio.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_EVENT 20
#define READ_BUF_LEN 256


static int make_socket_non_blocking (int fd) {
    int flags, s;
    // 获取当前flag
    flags = fcntl(fd, F_GETFL, 0);
    if (-1 == flags) {
        perror("Get fd status");
        return -1;
    }

    flags |= O_NONBLOCK;

    // 设置flag
    s = fcntl(fd, F_SETFL, flags);
    if (-1 == s) {
        perror("Set fd status");
        return -1;
    }
    return 0;
}


int main() {
    int epfd = 0;
    int listendfd = 0;
    int result = 0;

    struct epoll_event ev,event[MAX_EVENT];
    //
    const char *const local_addr = "0.0.0.0";
    struct sockaddr_in server_addr = {0};

    listendfd = socket(AF_INET,SOCK_STREAM,0);
    if( -1 == listendfd){
        perror("Open listen socket fail");
        return -1;
    }

    int on = 1;
    result = setsockopt(listendfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    if( -1 == result ){
        perror(" set socket fail");
        return 0;
    }
    //
    server_addr.sin_family = AF_INET;
    inet_aton(local_addr,&(server_addr.sin_addr));
    server_addr.sin_port = htons(8080);
    result = bind(listendfd,(const struct sockaddr *)&server_addr, sizeof(server_addr));
    if( -1 == result){
        perror("Bind Port Fail");
    }
    //non_blocking

    //
    result = listen(listendfd,200);
    if( -1 == result){
        perror("Start listen Fail");
        return 0;
    }

    epfd = epoll_create1(0);
    if( 1== epfd){
        perror("create epoll instance");
        return 0;
    }

    ev.data.fd = listendfd;
    ev.events =  EPOLLIN | EPOLLET;

    result = epoll_ctl(epfd,EPOLL_CTL_ADD,listendfd,&ev);
    if( -1 == result){
        perror("Set epoll_ctl");
        return 0;
    }


    for ( ; ; ) {
        int wait_count;
        // 等待事件
        wait_count = epoll_wait(epfd, event, MAX_EVENT, -1);

        for (int i = 0 ; i < wait_count; i++) {
            uint32_t events = event[i].events;
            // IP地址缓存
            char host_buf[NI_MAXHOST];
            // PORT缓存
            char port_buf[NI_MAXSERV];

            int __result;
            // 判断epoll是否发生错误
            if ( events & EPOLLERR || events & EPOLLHUP || (! events & EPOLLIN)) {
                printf("Epoll has error\n");
                close (event[i].data.fd);
                continue;
            } else if (listendfd == event[i].data.fd) {
                // listen的 file describe 事件触发， accpet事件

                for ( ; ; ) { // 由于采用了边缘触发模式，这里需要使用循环
                    struct sockaddr in_addr = { 0 };
                    socklen_t in_addr_len = sizeof (in_addr);
                    int accp_fd = accept(listendfd, &in_addr, &in_addr_len);
                    if (-1 == accp_fd) {
                        perror("Accept");
                        break;
                    }
                    __result = getnameinfo(&in_addr, sizeof (in_addr),
                                           host_buf, sizeof (host_buf) / sizeof (host_buf[0]),
                                           port_buf, sizeof (port_buf) / sizeof (port_buf[0]),
                                           NI_NUMERICHOST | NI_NUMERICSERV);

                    if (! __result) {
                        printf("New connection: host = %s, port = %s\n", host_buf, port_buf);
                    }

                    __result = make_socket_non_blocking(accp_fd);
                    if (-1 == __result) {
                        return 0;
                    }

                    ev.data.fd = accp_fd;
                    ev.events = EPOLLIN | EPOLLET;
                    // 为新accept的 file describe 设置epoll事件
                    __result = epoll_ctl(epfd, EPOLL_CTL_ADD, accp_fd, &ev);

                    if (-1 == __result) {
                        perror("epoll_ctl");
                        return 0;
                    }
                }
                continue;
            } else {
                // 其余事件为 file describe 可以读取
                int done = 0;
                // 因为采用边缘触发，所以这里需要使用循环。如果不使用循环，程序并不能完全读取到缓存区里面的数据。
                for ( ; ;) {
                    ssize_t result_len = 0;
                    char buf[READ_BUF_LEN] = { 0 };

                    result_len = read(event[i].data.fd, buf, sizeof (buf) / sizeof (buf[0]));

                    if (-1 == result_len) {
                        if (EAGAIN != errno) {
                            perror ("Read data");
                            done = 1;
                        }
                        break;
                    } else if (! result_len) {
                        done = 1;
                        break;
                    }

                    write(STDOUT_FILENO, buf, result_len);
                }
                if (done) {
                    printf("Closed connection\n");
                    close (event[i].data.fd);
                }
            }
        }

    }
    close (epfd);

    printf("Hello, World!\n");
    return 0;

}