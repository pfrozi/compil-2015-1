#include "cc_regs.h"

void  init_cc_regs(){
    
    id = 0;
}

char* get_reg(){
    
    char*   new_reg;
    
    new_reg = (char*)malloc(sizeof(char)*MAX_LEN);
    
    snprintf(new_reg, MAX_LEN, "r%d", id);
    
    id++;
    
    return new_reg;
}