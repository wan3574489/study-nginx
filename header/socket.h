//
// Created by WanZengchuang on 2018/9/18.
//

#ifndef EPOLL_FUNCTION_H
#define EPOLL_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include "config.h"

int getSocket(int *fd);
int bindAndListenSocket(const int fd,struct sockaddr_in *server_addr,int port,char const *local_addr);
int ConnectService(const int fd,struct sockaddr_in *server_addr,int port, char const *local_addr);
int getSocketBlock(int *fd);

#endif //EPOLL_FUNCTION_H
