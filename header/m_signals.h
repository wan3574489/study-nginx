
#ifndef EPOLL_SIGNALS_H
#define EPOLL_SIGNALS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define SIGTEST 34

typedef struct {
    int signo;
    char *name;
    void  (*handler)(int signo);
} m_signals;

int m_init_signals();
void signals_handler(int sig);

#endif //EPOLL_SIGNALS_H
