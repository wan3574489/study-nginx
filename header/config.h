//
// Created by WanZengchuang on 2018/9/26.
//

#ifndef EPOLL_CONFIG_H
#define EPOLL_CONFIG_H

#include "murmur.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/prctl.h>

#include "process.h"

#define MAX_EVENT 1024
#define READ_BUF_LEN 1024

#define  w_Success 0
#define  w_Fail  -1

#endif //EPOLL_CONFIG_H
