#include "cc_gencode.h" 
#include "cc_regs.h"
#include <stdlib.h>
#include <string.h>

void gen_literal(comp_tree_t* t)
{
    if(t->item->type==IKS_INT)
    {
    	t->item->num_codes=1;
    	t->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*));
        int val = t->item->sentry->val_int;
        char* reg1 = (char*)malloc(sizeof(char)*8);
        char* result = get_reg();
        iloc_code_t* code = get_iloc_code(OP_LOADI,reg1, NULL, result);
        t->item->codes[0] = code;
        t->item->result = result;
    }
}

void gen_add(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_ADD,t2->item->result,t3->item->result,result);
}

void gen_sub(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_SUB,t2->item->result,t3->item->result,result);
}

void gen_mul(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_MULT,t2->item->result,t3->item->result,result);
}

void gen_div(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_DIV,t2->item->result,t3->item->result,result);
}

void gen_and(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_AND,t2->item->result,t3->item->result,result);
}

void gen_or(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_OR,t2->item->result,t3->item->result,result);
}

void gen_log_and(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void gen_log_or(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void gen_less(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_CMP_LT,t2->item->result,t3->item->result,result);
}

void gen_greater(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_CMP_GT,t2->item->result,t3->item->result,result);
}

void gen_less_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_CMP_LE,t2->item->result,t3->item->result,result);
}

void gen_greater_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_CMP_GE,t2->item->result,t3->item->result,result);
}

void gen_equal(comp_tree_t* t1,comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_CMP_EQ,t2->item->result,t3->item->result,result);
}

void gen_unequal(comp_tree_t* t1,comp_tree_t* t2,comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    t1->item->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*)*t1->item->num_codes);
    memcpy(t1->item->codes,t2->item->codes,t2->item->num_codes);
    memcpy(t1->item->codes+t2->item->num_codes,t3->item->codes,t3->item->num_codes);
    t1->item->codes[t1->item->num_codes] = get_iloc_code(OP_CMP_NE,t2->item->result,t3->item->result,result);
}

void gen_if_else(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void gen_do_while(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void gen_while_do(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void gen_int_invert(comp_tree_t* t1)
{
}
