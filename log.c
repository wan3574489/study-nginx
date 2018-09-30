//
// Created by WanZengchuang on 2018/9/27.
//

#include "header/config.h"
#include "header/log.h"


int log_init(const char *conf_file){
    int rc;

    rc = zlog_init(conf_file);

    if (rc) {
        printf("init failed\n");
        return w_Fail;
    }

    zlog_category_instance = zlog_get_category("system");

    if (!zlog_category_instance) {
        printf("get cat fail\n");
        zlog_fini();
        return w_Fail;
    }

    return w_Success;
}

int log_free(){
    zlog_fini();
}