#include <unistd.h>
#include "header/config.h"
#include "epoll.h"
#include "socket.h"
#include "process.h"
#include "cycle.h"

int main(){
    int fd;
    struct sockaddr_in server_addr = {0};
    int port = 8080;
    const char *Service_addr = "127.0.0.1";

    if ( w_Fail == log_init("./config/log.conf") ){
        printf("初始化日志失败!");
        return 0;
    }

    if(getSocket(&fd) == w_Fail){
        return 0;
    }

    if( w_Fail == ConnectService(fd,&server_addr,port,Service_addr)){
        return 0;
    }

    char *s = "Hello Word!111";
    if(write(fd, s, strlen(s)) == -1){
        zlog_fatal(zlog_category_instance, "write fail");
        return 0;
    }

    close(fd);
    return 1;
}