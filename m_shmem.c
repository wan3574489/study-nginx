//
// Created by WanZengchuang on 2018/12/17.
//

#include "header/config.h"
#include "header/m_shmem.h"

extern int cpu_num;

int shemem_alloc(m_shmem_t *shm){

    shm->addr =(unsigned char *)mmap(NULL,shm->size,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1,0);

    zlog_info(zlog_category_instance, "shemem alloc");

    if( shm->addr == MAP_FAILED ){
        zlog_error(zlog_category_instance, "shemem alloc fail");
        return w_Fail;
    }

    bzero(shm->addr,shm->size);

    return w_Success;
}

int shemem_free(m_shmem_t *shm){

    if(-1 == munmap(shm->addr,shm->size)){
        zlog_error(zlog_category_instance, "shemem free fail");
        return w_Fail;
    }

    zlog_info(zlog_category_instance, "shemem free success");
    return w_Success;
}

int shmtx_create(m_shmtx_t *mtx,unsigned char *addr){

    mtx->lock = (atomic_t *)addr;

    if(mtx->spin == -1){
        return w_Success;
    }

    return w_Success;
}

int shmtx_lock(m_shmtx_t *mtx){
    int i,n;
    atomic_t val = 1;

    zlog_info(zlog_category_instance, "shmtx try lock");

    for(;;){


        val = (atomic_t)*mtx->lock;


        if(val == 0 && atomic_cmp_set(mtx->lock,0,1)){
            zlog_info(zlog_category_instance, "shmtx try lock success!");
            return w_Success;
        }


        if(cpu_num > 1){

            for ( n = 1; n < mtx->spin ;  n <<= 1) {


                for (i = 0; i < n ; i++) {
                        cpu_pause();
                }


                if(val == 0 && atomic_cmp_set(mtx->lock,0,1)){
                    zlog_info(zlog_category_instance, "shmtx try lock success!");
                    return w_Success;
                }

            }

        }

        sched_yield();
    }

    return w_Success;
}

int shmtx_unlock(m_shmtx_t *mtx){

    if(*mtx->lock != 1){
        return w_Success;
    }

    zlog_info(zlog_category_instance, "shmtx try unlock success!");

    atomic_cmp_set(mtx->lock,1,0);
    return w_Success;
}

int atomic_cmp_set(atomic_t *lock,int old,int set){
    unsigned int    res;

    __asm__ volatile (
    "lock"
    "   cmpxchgl  %3, %1;   "
    "   setz      %%al;     "
    "   movzbl    %%al, %0; "
    : "=a" (res) : "m" (*lock), "a" (old), "q" (set));

    return res;


}
