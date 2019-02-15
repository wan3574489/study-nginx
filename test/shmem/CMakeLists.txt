cmake_minimum_required(VERSION 3.7)

project(shmem)

set(CMAKE_C_STANDARD 99)

INCLUDE_DIRECTORIES(../../lib/hashtable)

aux_source_directory(../../lib/hashtable HASHTABLE_FILES)

### hashtable文件列表
add_executable(hashTable ${HASHTABLE_FILES})
