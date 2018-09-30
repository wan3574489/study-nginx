//
// Created by WanZengchuang on 2018/9/27.
//

#ifndef EPOLL_LOG_H
#define EPOLL_LOG_H

#include "zlog.h"

zlog_category_t *zlog_category_instance;

int log_init(const char *conf_file);
int log_free();

// #define LOG_INFO()  ( zlog_info(zlog_category_instance , "asdasd" ))

#endif //EPOLL_LOG_H
