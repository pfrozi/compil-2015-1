#ifndef __MISC_H
#define __MISC_H
#include <stdio.h>
#include "cc_dict.h"
#include "cc_stack.h"

extern int line_number;
extern comp_dict_t* stable;

int getLineNumber (void);
void yyerror (char const *mensagem);
void main_init (int argc, char **argv);
void main_finalize (void);

comp_dict_item_t* yystack_find(comp_dict_item_t* sentry);
void yystack_add(comp_dict_item_t* sentry);
#endif
