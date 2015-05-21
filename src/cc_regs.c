#include "cc_regs.h"

void  init_cc_regs(){
    
    id = 0;
}

char* get_reg(){
    
    char*   new_reg;
    
    char    buff1[6];
    char    buff2[4];

    new_reg = (char*)malloc(sizeof(buff1));
    
    strncpy( buff1, "r", 6 );
    itoa(id, buff2, 10);
    strncat(buff1, buff2, 6);

    strncpy( new_reg, buff1, 6);
    
    id++;
    
    return new_reg;
}