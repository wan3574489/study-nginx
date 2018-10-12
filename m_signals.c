//
// Created by WanZengchuang on 2018/10/9.
//

#include "header/config.h"
#include "header/m_signals.h"

int M_SIGALRM = 0,M_SIGINT = 0 ,M_SIGIO = 0,M_SIGCHLD = 0,M_SIGSYS = 0, M_SIGPIPE = 0,M_SIGTEST = 0;
int INT_END = -1;
int *ALL_SIGNALS[] = { &M_SIGALRM,&M_SIGINT,&M_SIGIO,&M_SIGCHLD,&M_SIGSYS,&M_SIGPIPE,&M_SIGTEST,&INT_END};


m_signals signals_coll[] = {

        { SIGALRM, "SIGALRM", signals_handler }, //时钟信号

       /* { SIGINT, "SIGINT",  signals_handler },  *///

        { SIGIO, "SIGIO",  signals_handler },    //文件描述符准备就绪

        { SIGCHLD, "SIGCHLD", signals_handler }, //子进程结束时, 父进程会收到这个信号

        { SIGSYS, "SIGSYS",  NULL },            //非法的系统调用

        { SIGPIPE, "SIGPIPE", NULL },           //管道破裂

        { SIGTEST, "M_SIGTEST", signals_handler },       //测试用的

        {0,"END",NULL}
};

int m_init_signals(){
    m_signals *si;
    struct sigaction sa;

    zlog_info(zlog_category_instance, " begin init signals ");

    for (si = signals_coll ; si->signo != 0;si++) {
        bzero(&sa, sizeof(struct sigaction ) );

        if(si->handler != NULL){
            sa.sa_handler = si->handler;
        }else{
            sa.sa_handler = SIG_IGN;
        }

        sigemptyset(&sa.sa_mask);
        if (sigaction(si->signo, &sa, NULL) == -1) {
            return w_Fail;
        }
    }

    return w_Success;

}

void signals_handler(int sig){

    zlog_info(zlog_category_instance, "signals trigger %d",sig);

    switch(sig){
        case SIGALRM:
            M_SIGALRM = 1;
            break;
        case SIGTEST:
            M_SIGTEST = 1;
            break;
        default:
            break;
    }

}