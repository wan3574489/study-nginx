//
// Created by WanZengchuang on 2018/9/18.
//

#ifndef EPOLL_EPOLL_H
#define EPOLL_EPOLL_H

#include <memory.h>
#include <malloc.h>
#include "config.h"
#include "epoll.h"
#include "socket.h"


typedef struct {
    int epfd;
    hash_table *ht;
}_epfd_ht;

typedef  struct {
    int fd;
    int epfd;
    struct epoll_event *ev;
    void (*call_back)(int fd, int events,int epfd, void *arg,_epfd_ht *epfd_ht);
    void *args;
}my_epoll_event;

int socketBindEpoll(int *epFd,int socketFd ,struct epoll_event *ev);

int waitClientConnect(int epfd,int socketFd,struct epoll_event event[],struct epoll_event *ev);
int make_socket_non_blocking (int fd);

void EpollWaitRead(int fd, int events,int epfd, void *arg,_epfd_ht *epfd_ht);
void EpollWaitAccept(int fd, int events,int epfd, void *arg,_epfd_ht *epfd_ht);
int initEpoll(int epfd,_epfd_ht **epfd_ht);
int initEpollEvent(int epfd,int fd,my_epoll_event **epollEvent);
int addEvent(int events,void (*call_back)(int, int,int,void*,_epfd_ht*),my_epoll_event *ev,_epfd_ht *epfd_ht);
int removeEvent(my_epoll_event *my_epoll_event_s,_epfd_ht *epfd_ht);

int waitTriggerEvent(int epFd,_epfd_ht *epfd_ht);

#endif //EPOLL_EPOLL_H
