//
// Created by WanZengchuang on 2018/10/11.
//

#ifndef EPOLL_CYCLE_H
#define EPOLL_CYCLE_H

#include <memory.h>
#include <malloc.h>
#include "config.h"
#include "m_shmem.h"

typedef struct  {
    int socket_fd;
    int epfd;
    int (*worker_callback)();

    //共享内存
    m_shmem_t *shm;
    //自旋锁
    m_shmtx_t *mtx;

}  m_cycle ;

int cycle_init(m_cycle **cycle);

#endif //EPOLL_CYCLE_H
