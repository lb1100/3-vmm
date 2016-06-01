#include "auxmem.h"
#include "global.h"
auxMem::auxMem() {
    if ((memFile = fopen(AUX_FILE, O_RDWR)) < 0){
        error_sys("Aux file open failed.");
    }
}

void auxMem::writePage(unsigned char* content, unsigned int addr) {
    if (fseek(memFile,addr,SEEK_SET)<0){
        error_sys("fseek failed.");
    }
    if (fwrite(content, 1, PAGE_SIZE, memFile) < PAGE_SIZE){
        error_sys("fwrite failed.");
    };
}

void auxMem::readPage(unsigned char* content, unsigned int addr) {
    if (fseek(memFile,addr,SEEK_SET)<0){
        error_sys("fseek failed.");
    }
    if (fread(content, 1, PAGE_SIZE, memFile) < PAGE_SIZE){
        error_sys("fread failed.");
    };
}

