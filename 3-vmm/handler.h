#ifndef HANDLER_H
#define HANDLER_H

#include "actmem.h"
#include "auxmem.h"

class handler {
    auxMem &auxmem;
    actMem &actmem;
public:
    handler(auxMem&,actMem&);
    void pageFault(unsigned int vaddr,unsigned int CR3);
    void freePGD(unsigned int pid);
    void switchPGD(unsigned int pid);
    void allocPGD(unsigned int pid);
};

#endif
