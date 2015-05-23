#ifndef __GENCODE_H
#define __GENCODE_H

#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_list.h"
#include "cc_operations.h"
#include "cc_regs.h"
#include <stdlib.h>
#include <string.h>


void gen_literal(comp_tree_t* t);
void gen_add(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_sub(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_mul(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_div(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_and(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_or(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_xor(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_log_and(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_log_or(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_less(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_greater(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_less_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_greater_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_equal(comp_tree_t* t1,comp_tree_t* t2, comp_tree_t* t3);
void gen_unequal(comp_tree_t* t1,comp_tree_t* t2,comp_tree_t* t3);
void gen_if_else(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3,comp_tree_t* t4);
void gen_do_while(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_while_do(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_int_invert(comp_tree_t* t1);


void gen_atrib_ident(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_atrib_array(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_atrib_addr(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);


void load_ident(comp_tree_t* t1);
void load_array(comp_tree_t* t1);

void get_addr_var_ident(comp_tree_t* t1);
void get_addr_var_array(comp_tree_t* t1);

#endif