#include "mmu.h"

mmu::mmu(actMem& act,handler& han){
    actmem = act; hand = han; flg = false;
}

unsigned int mmu::re_locate(unsigned int vaddr, int& status,bool read){
    unsigned int ax,ay,az,x,y;
    status = 1;
    ax = (CR3 & 0xfffff000) | (vaddr >> 20);
    if (flg && ax>=0xc0000000) {
        status = 0; return 0;
    } 
    
    x = actmem.readInt(ax);
    if (!ptePresent(x)){
        hand.pageFault(x, CR3);
    }
    ay = (x & 0xfffff000) | ((vaddr >> 10) & 0xffc);
    if (flg && ay>=0xc0000000) {
        status = 0; return 0;
    } 
    y = actmem.readInt(ay);
    
    if (!ptePresent((y))){
        hand.pageFault(y, CR3);
    }
    
    az = (y & 0xfffff000) | (vaddr & 0xfff);
    if (flg && az>=0xc0000000) {
        status = 0; return 0;
    } 
    return az;
}

unsigned int mmu::readInt(unsigned int vaddr, int& status){
    unsigned int addr = re_locate(vaddr, status, true);
    if (status){
        return actmem.readInt(addr);
    }
    else
        return 0;
}

void mmu::writeInt(unsigned int vaddr,unsigned int val, int& status){
    unsigned int addr = re_locate(vaddr, status);
    if (status)
        actmem.writeInt(addr, val);
}
    
unsigned char readChar(unsigned int vaddr, int& status){
    unsigned int addr = re_locate(vaddr, status);
    if (status)
        return actmem.readChar(addr);
    else
        return 0;
}
void writeChar(unsigned int vaddr, unsigned char val, int& status){
    unsigned int addr = re_locate(vaddr, status);
    if (status)
        actmem.writeInt(addr, val);
}
    
void readBytes(unsigned int vaddr, unsigned int len, unsigned char* target, int& status);
void writeBytes(unsigned int vaddr, unsigned int len, unsigned char* target, int& status);
