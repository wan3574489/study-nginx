//
// Created by WanZengchuang on 2018/10/11.
//

#ifndef EPOLL_CYCLE_H
#define EPOLL_CYCLE_H

#include <memory.h>
#include <malloc.h>
#include "config.h"

typedef struct  {
    int socket_fd;
    int (*worker_callback)();
}  m_cycle ;

int cycle_init(m_cycle **cycle);

#endif //EPOLL_CYCLE_H
