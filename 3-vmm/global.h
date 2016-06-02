#ifndef GLOBAL_H
#define GLOBAL_H


#define PAGE_SIZE (4096)
#define ACTMEM_SIZE (256*1048576)
#define AUXMEM_SIZE (1024*1048576)

#define ACT_PAGENUM (ACTMEM_SIZE/PAGE_SIZE)

#define AUX_FILE "auxMem"

void error_sys(const char* msg);

typedef unsigned int pte_t;

inline int ptePresent(pte_t x) { return x&1; }
inline int pteAllocated(pte_t x) { return (x>>1)&1; }
inline int pteAllowRead(pte_t x) { return (x>>2)&1; }
inline int pteAllowWrite(pte_t x) { return (x>>3)&1; }
inline int pteAddr(pte_t x) { return (x>>12); }

#endif
