#ifndef __GENCODE_H
#define __GENCODE_H

#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_list.h"
#include "cc_operations.h"
#include <stdlib.h>



char* assignment(comp_tree_t* node);


void gen_literal(comp_tree_t* t);
void gen_add(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_sub(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_mul(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);
void gen_div(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3);

void gen_int_invert(comp_tree_t* t1);
#endif