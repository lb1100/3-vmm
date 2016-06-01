#ifndef AUXMEM_H
#define AUXMEM_H
#include "global.h"
#include <stdio.h>
class auxMem {
private:
	FILE *memFile;
public:
	auxMem();
	
	void writePage(unsigned char* content, unsigned int addr);
	void readPage(unsigned char* content, unsigned int addr);
};

#endif
