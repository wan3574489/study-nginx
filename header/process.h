//
// Created by WanZengchuang on 2018/9/29.
//

#ifndef EPOLL_MULTIPROCESS_H
#define EPOLL_MULTIPROCESS_H

#include "config.h"

int my_daemon();
int create_worker(int number);
void set_proctitle(char** argv, const char* new_name);

#endif //EPOLL_MULTIPROCESS_H
