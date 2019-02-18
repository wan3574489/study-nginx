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

    if(getSocketBlock(&fd) == w_Fail){
        zlog_fatal(zlog_category_instance, "getSocketBlock fail");
        return 0;
    }

    if( w_Fail == ConnectService(fd,&server_addr,port,Service_addr)){
        zlog_fatal(zlog_category_instance, "ConnectService fail");
        return 0;
    }

    char *s = "Hello Word!111";
    if(write(fd, s, strlen(s)) == -1){
        zlog_fatal(zlog_category_instance, "write fail");
        return 0;
    }

    zlog_info(zlog_category_instance, "yes ");

    close(fd);
    return 1;
}