#include "actmem.h"

actMem::actMem(){
}

void actMem::writePage(unsigned char* content, unsigned int addr){
    unsigned char *ptr = Mem + addr;
    for(int i=0;i<PAGE_SIZE;i++){
        *(ptr++) = *(content++);
    }
}

void actMem::readPage(unsigned char* content, unsigned int addr){
    unsigned char *ptr = Mem + addr;
    for(int i=0;i<PAGE_SIZE;i++){
        *(content++) = *(ptr++);
    }
}
    
unsigned int actMem::readInt(unsigned int addr){
    unsigned char *ptr = Mem + addr;
    return ((*ptr) << 24) | ((*(ptr+1)) << 16) | (*(ptr+2) << 8) | (*(ptr+3)); 
}

void actMem::writeInt(unsigned int addr, unsigned int content){
    unsigned char *ptr = Mem + addr;
    *(ptr++) = (content >> 24) & 255;
    *(ptr++) = (content >> 16) & 255;
    *(ptr++) = (content >> 8) & 255;
    *ptr = content & 255;
}
    
unsigned char actMem::readChar(unsigned int addr){
    return Mem[addr];
}

void actMem::writeChar(unsigned int addr, unsigned char content){
    Mem[addr] = content;
}
