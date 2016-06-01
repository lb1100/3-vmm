#ifndef ACTMEM_H
#define ACTMEM_H
#include "global.h"

class actMem{
private:
    unsigned char Mem[ACTMEM_SIZE];
public:
    actMem();

    void writePage(unsigned char* content, unsigned int addr);
    void readPage(unsigned char* content, unsigned int addr);
    
    unsigned int readInt(unsigned int addr);
    void writeInt(unsigned int addr, unsigned int content);
    
    unsigned char readChar(unsigned int addr);
    void writeChar(unsigned int addr, unsigned char content);
};

#endif