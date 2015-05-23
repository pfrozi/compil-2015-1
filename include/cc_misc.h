#ifndef __MISC_H
#define __MISC_H
#include <stdio.h>
#include "cc_dict.h"
#include "cc_stack.h"
#include "main.h"

extern int line_number;
extern comp_dict_t* stable;

int getLineNumber (void);
void yyerror (char const *mensagem);
void main_init (int argc, char **argv);
void main_finalize (void);

int yyerror_var(comp_dict_item_t* sentry);

comp_dict_item_t* yystack_find_top(comp_dict_item_t* sentry);
comp_dict_item_t* yystack_find(comp_dict_item_t* sentry);

void yystack_add(comp_dict_item_t* sentry, int iks_type, int iks_var);
void yystack_update_var(comp_dict_item_t* sentry, comp_list_t* list_int , int var);

int yystack_verify_types(int type_a, int type_b);
int yystack_inf(comp_tree_item_t* sentry_a, comp_tree_item_t* sentry_b);
int yystack_set_type(comp_tree_t* root);
int yystack_return_type(comp_tree_t* root);
int yystack_type_co(int type_a, int type_b);

int yytree_match_types_out(comp_tree_t* root);
int yytree_match_arguments(comp_list_t* list, comp_list_t* args);

void yystack_push_scope();
void yystack_pop_scope();


int  define_type_size(int type);

void print_iloc_code(comp_tree_t* root);
void print_codes(list_codes_t* code);

#endif
