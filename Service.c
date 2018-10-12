
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include "header/config.h"


extern int M_SIGTEST;

int event(){
    int fd;
    struct sockaddr_in server_addr = {0};
    int port = 8080;
    const char *local_addr = "0.0.0.0";

    int epfd;
    _epfd_ht *epfd_ht;
    struct epoll_event ev,event[MAX_EVENT];
    int max_pid = 10;
    pid_t parentPid,_pid;

    my_epoll_event *epollEvent;

    if ( w_Fail == log_init("./config/log.conf") ){
        printf("初始化日志失败!");
        return 0;
    }

    if(getSocket(&fd) == w_Fail){
        return 0;
    }

    if(bindAndListenSocket(fd,&server_addr,port,local_addr) == w_Fail) {
        return 0;
    }

    epfd = epoll_create1(0);
    if( 1 == epfd){
        perror("create epoll instance");
        return 0;
    }

    if( initEpoll(epfd,&epfd_ht) == w_Fail){
        return 0;
    }

    if( w_Fail == initEpollEvent(epfd,fd,&epollEvent)){
        return 0;
    }

    if( addEvent(EPOLLIN | EPOLLET,EpollWaitAccept,epollEvent,epfd_ht) == w_Fail){
        return 0;
    }

    zlog_info(zlog_category_instance, "max_pid_number : %d",max_pid);

    close(epfd);
}



int main(int argc , char **argv){
    /*setenv("ZLOG_PROFILE_DEBUG","/root/c/log/zlog_debug.log",1);
    setenv("ZLOG_PROFILE_ERROR","/root/c/log/zlog_error.log",1);*/

    m_cycle *cycle;

    if ( w_Fail == cycle_init(&cycle)){
        zlog_error(zlog_category_instance, "cycle_init fail");
        return 0;
    }

    if ( w_Fail == log_init("./config/log.conf") ){
        printf("初始化日志失败!");
        return 0;
    }

    if ( w_Fail == m_init_signals()){
        zlog_error(zlog_category_instance, "m_init_signals fail");
        return 0;
    }

    int max_pid = 10;
    pid_t parentPid,_pid;

    sigset_t           set;

    sigemptyset(&set);
    sigaddset(&set, SIGCHLD);
    sigaddset(&set, SIGALRM);
    sigaddset(&set, SIGIO);
    sigaddset(&set, SIGSYS);
    sigaddset(&set, SIGPIPE);

    if (sigprocmask(SIG_BLOCK, &set, NULL) == -1) {
        zlog_error(zlog_category_instance, "sigprocmask block fail!");
    }

    sigemptyset(&set);

    parentPid = getpid();
    int parent = create_worker(max_pid);
    _pid = getpid();

    if(parentPid == _pid){

        char *new_name = "master";
        set_proctitle(argv,(const char *)new_name);

        printf("set_proctitle after argv %s\n", argv[0]);

        //监听并且阻塞信号
        zlog_info(zlog_category_instance, "master process pause");

        for(;;){

            //主进程阻塞信号
            sigsuspend(&set);

            if(M_SIGTEST){
                zlog_info(zlog_category_instance, "sig test process done!");
                M_SIGTEST = 0;
            }

        }

    }

}
