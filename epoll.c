//
// Created by WanZengchuang on 2018/9/18.
//

#include "header/epoll.h"

 int make_socket_non_blocking (int fd) {
    int flags, s;
    // 获取当前flag
    flags = fcntl(fd, F_GETFL, 0);
    if (-1 == flags) {
        perror("Get fd status");
        return -1;
    }

    flags |= O_NONBLOCK;

    // 设置flag
    s = fcntl(fd, F_SETFL, flags);
    if (-1 == s) {
        perror("Set fd status");
        return -1;
    }
    return 0;
}


void EpollWaitRead(int fd, int events,int epfd, void *arg,_epfd_ht *epfd_ht){

    // 其余事件为 file describe 可以读取
    int done = 0;
    // 因为采用边缘触发，所以这里需要使用循环。如果不使用循环，程序并不能完全读取到缓存区里面的数据。
    ssize_t result_len = 0;
    char buf[READ_BUF_LEN] = {0};

    my_epoll_event *my_epoll_event_s = (my_epoll_event *)malloc(sizeof(my_epoll_event));

    for ( ; ;) {
        done = 0;
        result_len = 0;
        bzero((void *)buf,READ_BUF_LEN);

        zlog_info(zlog_category_instance, "阻塞在等待read中");

        result_len = read(fd, buf, sizeof (buf) / sizeof (buf[0]));

        if (-1 == result_len) {

            if (EAGAIN != errno) {
                perror ("Read data");
                done = 1;
            }

            break;

        } else if (! result_len) {
            done = 1;
            break;
        }
        zlog_info(zlog_category_instance, "读取到数据 : %s",buf);
        zlog_info(zlog_category_instance, "done状态   : %d", done);

        done = 1;
        break;
    }

    if (done) {
        zlog_info(zlog_category_instance, "Closed connection %d ",fd);

        char *response = "HTTP/1.1 200 OK\r\nServer: openresty\r\n\r\nasdasdasdasd";
        if( write(fd,response,strlen(response)) == -1){
            zlog_info(zlog_category_instance, "写入反馈信息失败 ",fd);
        }

        bzero((void *)my_epoll_event_s, sizeof(my_epoll_event));
        my_epoll_event_s->fd = fd;
        my_epoll_event_s->epfd = epfd;
        removeEvent(my_epoll_event_s,epfd_ht);

        close (fd);
    }

}

void EpollWaitAccept(int fd, int events,int epfd, void *arg,_epfd_ht *epfd_ht){

    zlog_info(zlog_category_instance, "EpollWaitAccept r:%d",fd);

    // IP地址缓存
    char host_buf[NI_MAXHOST];
    // PORT缓存
    char port_buf[NI_MAXSERV];

    int __result;

    struct sockaddr in_addr = { 0 };
    socklen_t in_addr_len;

    int accp_fd;

    //
    for ( ; ; ) { // 由于采用了边缘触发模式，这里需要使用循环
        memset((void *)&in_addr,0, sizeof(struct sockaddr));
        in_addr_len = sizeof (in_addr);

        zlog_info(zlog_category_instance, "等待socket accept!");
        accp_fd = accept(fd, &in_addr, &in_addr_len);
        if (-1 == accp_fd) {
            perror("Accept fail!");
            break;
        }
        __result = getnameinfo(&in_addr, sizeof (in_addr),
                               host_buf, sizeof (host_buf) / sizeof (host_buf[0]),
                               port_buf, sizeof (port_buf) / sizeof (port_buf[0]),
                               NI_NUMERICHOST | NI_NUMERICSERV);

        if (! __result) {
            zlog_info(zlog_category_instance, "New connection: host = %s, port = %s", host_buf, port_buf);
        }

        __result = make_socket_non_blocking(accp_fd);
        if (-1 == __result) {
            return ;
        }

        my_epoll_event *epollEvent;

        if( w_Fail == initEpollEvent(epfd,accp_fd,&epollEvent)){
            return ;
        }

        if( addEvent(EPOLLIN | EPOLLET,EpollWaitRead,epollEvent,epfd_ht) == w_Fail){
            return ;
        }

        zlog_info(zlog_category_instance, "accept fd 被加入到epoll事件监听队列中fd : %d",accp_fd);

        break;
    }
}


int initEpoll(int epfd,_epfd_ht **epfd_ht){
    *epfd_ht = (_epfd_ht *)malloc(sizeof(_epfd_ht));
    if(epfd_ht == NULL){
        zlog_fatal(zlog_category_instance, "malloc失败");
        return w_Fail;
    }

    _epfd_ht *temp;
    temp = *epfd_ht;
    temp->epfd = epfd;
    temp->ht = (struct hash_table *)malloc(sizeof(struct hash_table));

    ht_init(temp->ht, HT_KEY_CONST | HT_VALUE_CONST, 0.05);

    return w_Success;
}

int  initEpollEvent(int epfd,int fd,my_epoll_event **epollEvent){
    *epollEvent = (my_epoll_event *)malloc(sizeof(my_epoll_event));

    if(epollEvent == NULL){
        zlog_fatal(zlog_category_instance, "malloc失败");
        return w_Fail;
    }

    bzero( *epollEvent, sizeof(my_epoll_event) );

    my_epoll_event *temp;
    temp = *epollEvent;

    temp->epfd = epfd;
    temp->fd   = fd;
    //初始化epollEvent  epoll_event
    temp->ev = (struct epoll_event *)malloc(sizeof(struct epoll_event));
    bzero( temp->ev, sizeof(struct epoll_event) );

    temp->ev->data.fd = fd;

    return w_Success;
}

int addEvent(int events,void (*call_back)(int, int,int,void*,_epfd_ht*),my_epoll_event *my_epoll_event_s,_epfd_ht *epfd_ht){

    int result;

    my_epoll_event_s->call_back = call_back;
    my_epoll_event_s->ev->events = events;

    result = epoll_ctl( my_epoll_event_s->epfd , EPOLL_CTL_ADD , my_epoll_event_s->fd , my_epoll_event_s->ev);

    if( -1 == result){
        perror("Set epoll_ctl");
        return w_Fail;
    }

    //zlog_info(zlog_category_instance, " epfd %d ",epfd_ht->epfd);

    ht_insert(epfd_ht->ht, (void *)&my_epoll_event_s->fd, sizeof(my_epoll_event_s->fd), (void *)my_epoll_event_s, sizeof(my_epoll_event_s));

    return w_Success;
}

int removeEvent(my_epoll_event *my_epoll_event_s,_epfd_ht *epfd_ht){
    int result;

    //从epoll中删除
    result = epoll_ctl( my_epoll_event_s->epfd , EPOLL_CTL_DEL , my_epoll_event_s->fd , NULL);

    if( -1 == result){
        perror("Set epoll_ctl");
        return w_Fail;
    }
    //从ht中删除
    ht_remove(epfd_ht->ht, (void *)&my_epoll_event_s->fd, sizeof(my_epoll_event_s->fd));

    return w_Success;
}

int socketBindEpoll(int *epFd,int socketFd ,struct epoll_event *ev){
    int result;
    *epFd = epoll_create1(0);

    if( 1== *epFd){
        perror("create epoll instance");
        return 0;
    }

    ev->data.fd = socketFd;
    ev->events =  EPOLLIN | EPOLLET;

    result = epoll_ctl(*epFd,EPOLL_CTL_ADD,socketFd,ev);
    if( -1 == result){
        perror("Set epoll_ctl");
        return w_Fail;
    }

    return w_Success;
}

int waitTriggerEvent(int epfd,_epfd_ht *epfd_ht){

    int wait_count ;
    struct epoll_event events[MAX_EVENT];
    uint32_t event;
    int fd ;
    size_t value_size;

    for ( ; ; ) {

        zlog_info(zlog_category_instance, "等待事件触发!");
        // 等待事件
        wait_count = epoll_wait(epfd, events, MAX_EVENT, -1);

        zlog_info(zlog_category_instance, "事件触发，总数:%d",wait_count);

        for (int i = 0 ; i < wait_count; i++) {
            event = events[i].events;
            fd = events[i].data.fd;

            if ( event & EPOLLERR || event & EPOLLHUP || (! event & EPOLLIN)) {
                printf("Epoll has error\n");
                close (events[i].data.fd);
                continue;
            }
            value_size = 0;
            my_epoll_event *got = (my_epoll_event *)ht_get(epfd_ht->ht, (void *)&fd, sizeof(int), &value_size);
            if(value_size <= 0){
                zlog_info(zlog_category_instance, "从哈希表中搜索%d , 没有获取到结果 ",fd);
                continue;
            }

            zlog_info(zlog_category_instance, "要搜索的结果是 %d ,从hashtable中搜索到结果fd:%d ",fd,got->fd);
            got->call_back(fd,event,epfd,got->args,epfd_ht);
        }

    }

    return 0;
}

int waitClientConnect(int epfd,int socketFd,struct epoll_event event[],struct epoll_event *ev){

    int wait_count;

    uint32_t events;
    // IP地址缓存
    char host_buf[NI_MAXHOST];
    // PORT缓存
    char port_buf[NI_MAXSERV];

    int __result;

    struct sockaddr in_addr = { 0 };
    socklen_t in_addr_len;

    int accp_fd;

    for ( ; ; ) {

        zlog_info(zlog_category_instance, "等待socket事件触发!");
        // 等待事件
        wait_count = epoll_wait(epfd, event, MAX_EVENT, -1);

        zlog_info(zlog_category_instance, "事件触发，总数:%d",wait_count);

        for (int i = 0 ; i < wait_count; i++) {

             events = event[i].events;

            if ( events & EPOLLERR || events & EPOLLHUP || (! events & EPOLLIN)) {
                printf("Epoll has error\n");
                close (event[i].data.fd);
                continue;

            }else if (socketFd == event[i].data.fd) {    // listen的 file describe 事件触发， accpet事件

                zlog_info(zlog_category_instance, "service socket 被触发fd : %d",socketFd);

                for ( ; ; ) { // 由于采用了边缘触发模式，这里需要使用循环
                    memset((void *)&in_addr,0, sizeof(struct sockaddr));
                    in_addr_len = sizeof (in_addr);

                    zlog_info(zlog_category_instance, "等待socket accept!");
                    accp_fd = accept(socketFd, &in_addr, &in_addr_len);
                    if (-1 == accp_fd) {
                        perror("Accept fail!");
                        break;
                    }
                    __result = getnameinfo(&in_addr, sizeof (in_addr),
                                           host_buf, sizeof (host_buf) / sizeof (host_buf[0]),
                                           port_buf, sizeof (port_buf) / sizeof (port_buf[0]),
                                           NI_NUMERICHOST | NI_NUMERICSERV);

                    if (! __result) {
                        zlog_info(zlog_category_instance, "New connection: host = %s, port = %s", host_buf, port_buf);
                    }

                    __result = make_socket_non_blocking(accp_fd);
                    if (-1 == __result) {
                        return 0;
                    }

                    ev->data.fd = accp_fd;
                    ev->events = EPOLLIN | EPOLLET;
                    // 为新accept的 file describe 设置epoll事件
                    __result = epoll_ctl(epfd, EPOLL_CTL_ADD, accp_fd, ev);

                    if (-1 == __result) {
                        perror("epoll_ctl");
                        return 0;
                    }
                    zlog_info(zlog_category_instance, "accept fd 被加入到epoll事件监听队列中fd : %d",accp_fd);

                    break;
                }
                continue;

            }else{

                // 其余事件为 file describe 可以读取
                int done = 0;
                // 因为采用边缘触发，所以这里需要使用循环。如果不使用循环，程序并不能完全读取到缓存区里面的数据。
                for ( ; ;) {
                    ssize_t result_len = 0;
                    char buf[READ_BUF_LEN] = { 0 };

                    result_len = read(event[i].data.fd, buf, sizeof (buf) / sizeof (buf[0]));

                    if (-1 == result_len) {
                        if (EAGAIN != errno) {
                            perror ("Read data");
                            done = 1;
                        }
                        break;
                    } else if (! result_len) {
                        done = 1;
                        break;
                    }

                    zlog_info(zlog_category_instance, "读取到数据 : %s",buf);

                    break;

                }

                if (done) {
                    printf("Closed connection\n");
                    close (event[i].data.fd);
                }

            }

        }
    }

    return 0;

}