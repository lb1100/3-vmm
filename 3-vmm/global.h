#ifndef GLOBAL_H
#define GLOBAL_H

#define PAGE_SIZE (4096)
#define ACTMEM_SIZE (256*1048576)
#define AUXMEM_SIZE (1024*1048576)

#define AUX_FILE "auxMem"

void error_sys(const char* msg){
    perror(msg);
    exit(1);
};

#endif