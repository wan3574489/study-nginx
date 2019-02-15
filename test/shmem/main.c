#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include "config.h"
#include "epoll.h"
#include "socket.h"
#include "process.h"
#include "cycle.h"
#include "m_shmem.h"

int main(void)
{

    m_shmem_t shm = {0};
    m_shmtx_t mtx = {0};

    shm.size = 4096;

    if ( shemem_alloc(&shm) == w_Fail ){
        return w_Fail;
    }

    if(  shmtx_create(&shm,shm.addr) == w_Fail ){
        return w_Fail;
    }

}

