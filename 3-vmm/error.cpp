#include <stdio.h>
#include <stdlib.h>
void error_sys(const char* msg){
    perror(msg);
    exit(1);
}
