//
// Created by WanZengchuang on 2018/10/12.
//

#include "header/m_event.h"
#include "header/epoll.h"
#include "header/socket.h"
#include "header/process.h"
#include "header/m_signals.h"

int init_event(m_cycle *cycle){
    int fd;
    struct sockaddr_in server_addr = {0};
    int port = 8080;
    const char *local_addr = "0.0.0.0";

    if(getSocket(&fd) == w_Fail){
        return w_Fail;
    }

    if(bindAndListenSocket(fd,&server_addr,port,local_addr) == w_Fail) {
        return w_Fail;
    }

    cycle->socket_fd = fd;

    epfd = epoll_create1(0);
    if( 1 == epfd){
        zlog_error(zlog_category_instance, "create epoll instance ");
        return w_Fail;
    }

    return w_Success;
}

int event(){
    int fd;
    struct sockaddr_in server_addr = {0};
    int port = 8080;
    const char *local_addr = "0.0.0.0";

    int epfd;
    _epfd_ht *epfd_ht;
    struct epoll_event ev,event[MAX_EVENT];
    int max_pid = 10;
    pid_t parentPid,_pid;

    my_epoll_event *epollEvent;

    if ( w_Fail == log_init("./config/log.conf") ){
        printf("初始化日志失败!");
        return 0;
    }

    if(getSocket(&fd) == w_Fail){
        return 0;
    }

    if(bindAndListenSocket(fd,&server_addr,port,local_addr) == w_Fail) {
        return 0;
    }

    epfd = epoll_create1(0);
    if( 1 == epfd){
        perror("create epoll instance");
        return 0;
    }

    if( initEpoll(epfd,&epfd_ht) == w_Fail){
        return 0;
    }

    if( w_Fail == initEpollEvent(epfd,fd,&epollEvent)){
        return 0;
    }

    if( addEvent(EPOLLIN | EPOLLET,EpollWaitAccept,epollEvent,epfd_ht) == w_Fail){
        return 0;
    }

    zlog_info(zlog_category_instance, "max_pid_number : %d",max_pid);

    close(epfd);
}