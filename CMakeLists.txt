cmake_minimum_required(VERSION 3.7)

project(epoll)

INCLUDE_DIRECTORIES(lib/zlog)
INCLUDE_DIRECTORIES(header)
INCLUDE_DIRECTORIES(lib/hashtable)

set(CMAKE_C_STANDARD 99)

###Zlog编译文件列表
aux_source_directory(./lib/zlog/ ZLOG_SRCS)
list(REMOVE_ITEM ZLOG_SRCS ./lib/zlog/zlog-chk-conf.c)

### hashtable文件列表
add_definitions("-D__WITH_MURMUR")

set(HASHTABLE_FILES lib/hashtable/hashtable.c lib/hashtable/hashtable.h lib/hashtable/murmur.h lib/hashtable/murmur.c)
set(ALL_FILES socket.c header/config.h header/socket.h epoll.c header/epoll.h  log.c header/log process.c header/process.h)

set(SOURCE_FILES main.c header/config.h)
set(SERVICE_SOURCE_FILES Service.c ${ALL_FILES} ${HASHTABLE_FILES})
set(SERVICE_CLIENT_FILES Client.c  ${ALL_FILES} ${HASHTABLE_FILES})

##set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./build/Relase)

find_package( Threads )
add_library(zlog_s STATIC ${ZLOG_SRCS})
target_link_libraries(zlog_s ${CMAKE_THREAD_LIBS_INIT})

#add_executable(epoll ${SOURCE_FILES})
add_executable(Service ${SERVICE_SOURCE_FILES})
add_executable(Client ${SERVICE_CLIENT_FILES})

### 链接 zlog库
target_link_libraries(Service zlog_s)
target_link_libraries(Client zlog_s)