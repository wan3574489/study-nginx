//
// Created by WanZengchuang on 2018/9/29.
//

#ifndef EPOLL_MULTIPROCESS_H
#define EPOLL_MULTIPROCESS_H

#include "config.h"
#include "cycle.h"

int my_daemon();
int create_worker(int number,m_cycle *cycle);
void set_proctitle(char** argv, const char* new_name);

int worker_callback();

#endif //EPOLL_MULTIPROCESS_H
