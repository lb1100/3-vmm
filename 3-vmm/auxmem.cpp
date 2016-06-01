#include "auxmem.h"

auxMem::auxMem() {
    if ((memFile = fopen(AUX_FILE, "r+")) < 0){
        error_sys("Aux file open failed.");
    }
}

void auxMem::writePage(unsigned char* content, unsigned int addr) {
    if (fseek(memFile,addr*PAGE_SIZE,SEEK_SET)<0){
        error_sys("fseek failed.");
    }
    if (fwrite(content, 1, PAGE_SIZE, memFile) < PAGE_SIZE){
        error_sys("fwrite failed.");
    };
}

void auxMem::readPage(unsigned char* content, unsigned int addr) {
    if (fseek(memFile,addr*PAGE_SIZE,SEEK_SET)<0){
        error_sys("fseek failed.");
    }
    if (fread(content, 1, PAGE_SIZE, memFile) < PAGE_SIZE){
        error_sys("fread failed.");
    };
}
