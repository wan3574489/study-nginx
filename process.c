//
// Created by WanZengchuang on 2018/9/29.
//

#include "config.h"
#include "log.h"
#include "header/cycle.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <string.h>
#include <cycle.h>
#include <time.h>

extern char **environ;

#define MAX_DELAY 10240
#define MIN_DELAY 2

int  my_daemon(){
    int  fd;
    switch (fork()) {
        case -1:
            zlog_fatal(zlog_category_instance, "my_daemon fork 失败");
            return w_Fail;
        case 0:
            break;
        default:
            exit(0);
    }

    if ((fd = open("/dev/null", O_RDWR, 0)) != -1) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) close(fd);
    }

    return w_Success;

}

int create_worker(int number,m_cycle *cycle){
    int i ;
    pid_t pid;

    for (i = 0; i < number; ++i) {
        pid=fork();
        zlog_info(zlog_category_instance, "fork after : %d",pid);

        switch(pid){
            case 0:
                zlog_info(zlog_category_instance, "I am the child process, my process id is %d", getpid());

                //干自己的事情
                if(w_Fail == cycle->worker_callback(cycle)){
                    zlog_info(zlog_category_instance, "worker_callback is Fail");
                    return w_Fail;
                }

                break;

            case -1:
                perror("fork");
                return w_Fail;
            default:
                zlog_info(zlog_category_instance, "I am the parent process, my process id is %d", getpid());
                break;
        }
    }

    return w_Success;
}

int worker_callback(m_cycle *cycle){

    zlog_info(zlog_category_instance, "I am in worker_callback");

    int  has_lock = 0;
    int wait_count;
    struct epoll_event event[1024];
    int delay = MAX_DELAY << 1;

    for(;;){

        if(shmtx_lock(cycle->mtx) == w_Success){

            has_lock = 1;

            //设置事件监听
            if( addEvent(EPOLLIN | EPOLLET,EpollWaitAccept,cycle->epollEvent,cycle->epfd_ht) == w_Fail){

                zlog_info(zlog_category_instance, "addEvent epollWaitAccetp error ! ");

                return w_Fail;
            }
        }


        // 等待事件
        wait_count = epoll_wait(cycle->epfd, event, 1024, delay);


        if( wait_count > 0){

            if(removeEvent(cycle->epollEvent,cycle->epfd_ht) == w_Fail){

                zlog_info(zlog_category_instance, "removeEvent epollWaitAccetp error ! ");

                return w_Fail;
            }


            zlog_info(zlog_category_instance, "wait_count most event ! ");
            if(delay > MIN_DELAY){
                delay >> 1;
            }

            //等待读取数据
            for (int i = 0 ; i < wait_count; i++) {
                uint32_t events = event[i].events;

                if( events == EPOLLIN | EPOLLET ){
                    if(cycle->socket_fd == event[i].data.fd){
                        EpollWaitAccept(event[i].data.fd,events,cycle->epfd,NULL,cycle->epfd_ht);
                    }else{
                        EpollWaitRead(event[i].data.fd,events,cycle->epfd,NULL,cycle->epfd_ht);
                    }
                }

            }


        }else{
            zlog_info(zlog_category_instance, "wait_count == 0");
            if(delay < MAX_DELAY ){
                delay << 1;
            }
        }


        if(has_lock == 1){

            if(removeEvent(cycle->epollEvent,cycle->epfd_ht) == w_Fail){

                zlog_info(zlog_category_instance, "removeEvent epollWaitAccetp error ! ");

                return w_Fail;
            }

            shmtx_unlock(cycle->mtx);

            has_lock = 0;

        }

    }

}

void set_proctitle(char** argv, const char* new_name)
{

    int size = 0;
    int i;

    int my_new_name_size  = strlen(new_name)+strlen(argv[0])+2+3;

    //todo 需要精简掉 太Low
    char *my_new_name = (char*)malloc(my_new_name_size);
    char *t = my_new_name;
    strcpy(my_new_name,argv[0]);
    my_new_name += strlen(argv[0]);
    strcpy(my_new_name,"(");
    my_new_name++;
    strcpy(my_new_name,new_name);
    my_new_name += strlen(new_name);
    strcpy(my_new_name,")");
    my_new_name++;
    new_name = t;

    // 申请新的空间存放 environ 中内容
    for (i = 0; environ[i]; i++) {
        size += strlen(environ[i]) + 1;
    }

    char* p = (char*)malloc(size);
    char* last_argv = argv[0];

    for (i = 0; argv[i]; i++) {
        //argv的值只有一个，但是environ变量的内存紧跟在argv变量内存的后面
        if (last_argv == argv[i]) {
            //last_argv 最后取得的是environ的第一个???
            last_argv = argv[i] + strlen(argv[i]) + 1;
        }
    }

    //last_argv 这个时候指向的就是environ第一个变量了
    for (i = 0; environ[i]; i++) {
        if (last_argv == environ[i]) {
            size = strlen(environ[i]) + 1;
            last_argv = environ[i] + size;

            memcpy(p, environ[i], size);
            environ[i] = (char*)p;
            p += size;
        }
    }

    last_argv--;

    // 修改 argv[0]，argv剩余的空间全部填0
    strncpy( argv[0], new_name, last_argv - argv[0]);

    p = argv[0] + strlen(argv[0]) + 1;
    if (last_argv - p > 0) {
        memset(p, 0, last_argv - p);
    }

}