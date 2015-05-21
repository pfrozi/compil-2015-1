#include "cc_regs.h"

void  init_cc_regs(){
    
    id = 0;
}

char* get_reg(){
    
    char*   new_reg;
    char[2] buff1 = "r";
    char[4] buff2;
    
    itoa(id, buff2, 10);
    
    strncat(buff1, buff2, 6);
    
    id++;
    
    return new_reg;
}