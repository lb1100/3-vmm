#ifndef HANDLER_H
#define HANDLER_H

#include "mmu.h"
#include "actmem.h"
#include "auxmem.h"

class handler {
    auxMem &auxmem;
    actMem &actmem;
    mmu &mmu;
public:
    handler(auxMem&,actMem&);
    void setMMU(mmu&);
    void pageFault(unsigned int vaddr);
    void freePGD(unsigned int pid);
    void switchPGD(unsigned int pid);
    void allocPGD(unsigned int pid);
};

#endif
