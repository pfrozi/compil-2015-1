#include "cc_rot.h"

void  init_cc_rot(){
    
    id = 0;
}

char* get_rot(){
    
    char*   new_reg;
    
    new_reg = (char*)malloc(sizeof(char)*MAX_LEN);
    
    snprintf(new_reg, MAX_LEN, "l%d", id);
    
    id++;
    
    return new_reg;
}