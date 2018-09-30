//
// Created by WanZengchuang on 2018/9/18.
//

#include "header/socket.h"
#include "header/epoll.h"



int getSocket(int *fd){
    int result,__result;

    *fd = socket(AF_INET,SOCK_STREAM,0);
    if( -1 == *fd){
        perror("Open listen socket fail");
        return w_Fail;
    }

    int on = 1;
    result = setsockopt(*fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    if( -1 == result ){
        perror(" set socket fail");
        return w_Fail;
    }
    __result = make_socket_non_blocking(*fd);
    if (-1 == __result) {
        zlog_fatal(zlog_category_instance, "设置socket非阻塞失败");
        return w_Fail;
    }

    return  w_Success;
}

int bindAndListenSocket(const int fd,struct sockaddr_in *server_addr,int port, char const *local_addr){
    int result ;

    server_addr->sin_family = AF_INET;
    inet_aton(local_addr,&(server_addr->sin_addr));
    server_addr->sin_port = htons(port);

    result = bind(fd,(struct sockaddr *)server_addr, sizeof(*server_addr));

    if( -1 == result){
        perror("Bind Port Fail");
        return w_Fail;
    }

    result = listen(fd,200);
    if( -1 == result){
        perror("Start listen Fail");
        return w_Fail;
    }

    return w_Success;
}

int ConnectService(const int fd,struct sockaddr_in *server_addr,int port, char const *local_addr){
    int result;

    server_addr->sin_family = AF_INET;
    inet_aton(local_addr,&(server_addr->sin_addr));
    server_addr->sin_port = htons(port);

    result = connect( fd, (const struct sockaddr *)server_addr, sizeof(*server_addr));
    if(-1 == result ){
        perror("connect Fail");
        return w_Fail;
    }

    return w_Success;
}