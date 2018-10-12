//
// Created by WanZengchuang on 2018/10/11.
//

#include "header/cycle.h"

int cycle_init(m_cycle **cycle){

    m_cycle *temp;

    *cycle = (m_cycle *)malloc(sizeof(m_cycle));
    if(cycle == NULL){
        zlog_fatal(zlog_category_instance, "malloc失败");
        return w_Fail;
    }

    temp->worker_callback = worker_callback;

    return w_Success;

}
