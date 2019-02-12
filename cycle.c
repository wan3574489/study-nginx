//
// Created by WanZengchuang on 2018/10/11.
//

#include <string.h>
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




    temp = *cycle;
    temp->worker_callback = worker_callback;

    temp->shm = (m_shmem_t *)malloc(sizeof(m_shmem_t));
    bzero(temp->shm, sizeof(m_shmem_t));
    temp->shm->size = 4096;

    //temp->shm ->addr = (unsigned char *)malloc(sizeof(unsigned char)* 4096);
    //bzero(temp->shm->addr, sizeof(unsigned char)* 4096);

    temp->mtx = (m_shmtx_t *)malloc(sizeof(m_shmtx_t));


    if(w_Fail == init_event(*cycle)){
        zlog_fatal(zlog_category_instance, "init_event 失败");
        return w_Fail;
    }

    zlog_debug(zlog_category_instance, "cycle socket  %d ",temp->socket_fd);

    return w_Success;
}
