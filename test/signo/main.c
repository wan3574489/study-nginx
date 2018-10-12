#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

static void sig_alrm(int signo)
{
    printf("received SIGALRM\n");
}

static void signo_handler(int signo){

}

int main(void)
{

    printf("当前id %d\n",getpid());

    sigset_t    sigset;
    int a;

    //  初始化信号集
    sigemptyset(&sigset);

    // 添加多个阻塞信号
    sigaddset(&sigset, 62);
    sigaddset(&sigset, 63);
    sigaddset(&sigset, 64);
    sigaddset(&sigset, 65);
    sigaddset(&sigset, 66);

    if (sigprocmask(SIG_BLOCK, &sigset, NULL) < 0)
    {
        printf("sigprocmask error: %s\n", strerror(errno));
        exit(-1);
    }
    else
    {
        printf("signal SIGALARM is in in sigset now...\n");
    }

    sigemptyset(&sigset);


    if (signal(62, sig_alrm) < 0)          //  添加信号处理函数
    {
        printf("signal error: %s\n", strerror(errno));
        exit(-1);
    }

    while(1){

        printf("signo sigsuspend \n");

        sigsuspend(&sigset);
    }


    return 0;
}

