//
// Created by WanZengchuang on 2018/10/11.
//

#ifndef EPOLL_CYCLE_H
#define EPOLL_CYCLE_H

#include <memory.h>
#include <malloc.h>
#include "config.h"

 struct _m_cycle {
    int socket_fd;
    int (*worker_callback)();
}  ;

typedef  struct _m_cycle m_cycle;


int cycle_init(m_cycle **cycle);

#endif //EPOLL_CYCLE_H
