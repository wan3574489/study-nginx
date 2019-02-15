//
// Created by WanZengchuang on 2018/12/17.
//

#ifndef EPOLL_M_SHMEM_H
#define EPOLL_M_SHMEM_H

#include <sys/mman.h>
#include <sched.h>
#include <string.h>


//unsigned long 32位
typedef volatile unsigned long atomic_t;



typedef struct {
    int size;
    //unsigned char 无符号整形
    unsigned char *addr;
} m_shmem_t;

typedef struct {
    atomic_t   *lock;
    int     spin;
}m_shmtx_t;


//共享内存申请与释放
int shemem_alloc(m_shmem_t *shm);
int shemem_free(m_shmem_t *shm);

//自旋锁的操作
int shmtx_create(m_shmtx_t *mtx,unsigned char *addr);
int shmtx_lock(m_shmtx_t *mtx);
int shmtx_unlock(m_shmtx_t *mtx);

//原子操作
int atomic_cmp_set(atomic_t *lock,int old,int set);

//让出CPU
#define cpu_pause()             __asm__ ("pause")

#endif //EPOLL_M_SHMEM_H
