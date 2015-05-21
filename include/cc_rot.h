/*
  cc_rot.h

  Retorna um rótulo único a cada chamada da função get_rotulo()

  Formato do rótudo:
*/
#ifndef __CC_ROT_H__
#define __CC_ROT_H__

#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 5

int id;

void  init_cc_rot();
char* get_rot();
    

#endif
