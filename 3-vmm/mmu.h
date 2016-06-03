#ifndef MMU_H
#define MMU_H

#include "actmem.h"
#include "handler.h"

class mmu {
private:
    actMem &actmem;
    handler &hand;
    unsigned int CR3;
    bool flg;
    unsigned int re_locate(unsigned int vaddr, int& status);
public:
    mmu(actMem&,handler&);
    
    unsigned int readInt(unsigned int vaddr, int& status);
    void writeInt(unsigned int vaddr,unsigned int val, int& status);
    
    unsigned char readChar(unsigned int vaddr, int& status);
    void writeChar(unsigned int vaddr, unsigned char val, int& status);
    
    void readBytes(unsigned int vaddr, unsigned int len, unsigned char* target, int& status);
    void writeBytes(unsigned int vaddr, unsigned int len, unsigned char* target, int& status);
    
    unsigned int getCR3() { return CR3; }
    void setCR3(unsigned int val) { CR3=val; }
};

#endif
