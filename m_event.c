#include "header/m_event.h"
#include "header/epoll.h"
#include "header/socket.h"
#include "header/process.h"
#include "header/m_signals.h"
#include <stdio.h>
#include <unistd.h>
#include <cycle.h>

int cpu_num;

int init_event(m_cycle *cycle){
    int fd;
    struct sockaddr_in server_addr = {0};
    int port = 8080;
    const char *local_addr = "0.0.0.0";


    cpu_num = sysconf(_SC_NPROCESSORS_CONF);

    if(getSocket(&fd) == w_Fail){
        return w_Fail;
    }
    if(bindAndListenSocket(fd,&server_addr,port,local_addr) == w_Fail) {
        return w_Fail;
    }

    cycle->socket_fd = fd;
    cycle->epfd = epoll_create1(0);


    if( 1 == cycle->epfd){
        zlog_error(zlog_category_instance, "create epoll instance ");
        return w_Fail;
    }

    if( initEpoll(cycle->epfd,&cycle->epfd_ht) == w_Fail){
        return w_Fail;
    }

    if( w_Fail == initEpollEvent(cycle->epfd,cycle->socket_fd,&cycle->epollEvent)){
        return w_Fail;
    }


    if(shemem_alloc(cycle->shm) == w_Fail){
        zlog_error(zlog_category_instance, "shemem alloc fail ");
        return w_Fail;
    }


    if(shmtx_create(cycle->mtx,cycle->shm->addr) == w_Fail){
        zlog_error(zlog_category_instance, "shmtx create fail ");
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