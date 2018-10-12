//
// Created by WanZengchuang on 2018/10/11.
//

#include "header/cycle.h"
#include "header/process.h"
#include "header/m_event.h"

int cycle_init(m_cycle **cycle){

    m_cycle *temp;

    *cycle = (m_cycle *)malloc(sizeof(m_cycle));
    if(cycle == NULL){
        zlog_fatal(zlog_category_instance, "malloc失败");
        return w_Fail;
    }

    if(w_Fail == init_event(*cycle)){
        zlog_fatal(zlog_category_instance, "init_event 失败");
        return w_Fail;
    }

    temp = *cycle;
    temp->worker_callback = worker_callback;

    zlog_debug(zlog_category_instance, "cycle socket  %d ",temp->socket_fd);


    return w_Success;
}
