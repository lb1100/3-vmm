#ifndef MMU_H
#define MMU_H

#include "actmem.h"
#include "handler.h"

class mmu {
private:
    actMem &actmem;
    handler &hand;
    unsigned int CR3;
public:
    mmu(actMem&,handler&);
    
    unsigned int readInt(unsigned int vaddr);
    void writeInt(unsigned int vaddr,unsigned int val);
    
    unsigned char readChar(unsigned int vaddr);
    void writeChar(unsigned int vaddr, unsigned char val);
    
    void readBytes(unsigned int vaddr, unsigned int len, unsigned char* target);
    void writeBytes(unsigned int vaddr, unsigned int len, unsigned char* target);
    
    unsigned int getCR3() { return CR3; }
    void setCR3(unsigned int val) { CR3=val; }
};

#endif
