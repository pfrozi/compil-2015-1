#include "cc_gencode.h" 
#include "cc_regs.h"
#include <stdlib.h>
#include <string.h>

void gen_literal(comp_tree_t* t)
{
    if(t->item->type==IKS_INT)
    {
    	t->item->num_codes=1;
        int val = t->item->sentry->val_int;
        char* result = get_reg();
        
        iloc_code_t* code = load_immediate(result, val);
        t->item->codes = list_codes_create(code);
        t->item->result = result;
    }
    else if(t->item->type==IKS_BOOL)
    {
    	t->item->num_codes=1;
        int val = t->item->sentry->val_int;
        char* reg1 = (char*)malloc(sizeof(char)*8);
        char* result = get_reg();
        iloc_code_t* code=NULL;
        if(t->item->sentry->val_bool)
        {
             code = load_immediate(result, 1);
        }
        else
        {
             code = load_immediate(result, 0);
        }
        t->item->codes = list_codes_create(code);
        t->item->result = result;
    }
}

void gen_add(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes,list_codes_create(get_iloc_code(OP_ADD,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_sub(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_SUB,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_mul(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_MULT,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_div(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_DIV,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_and(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_AND,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_or(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_OR,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_xor(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_XOR,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
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
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_CMP_LT,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_greater(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_CMP_GT,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_less_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_CMP_LE,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_greater_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_CMP_GE,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_equal(comp_tree_t* t1,comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_CMP_EQ,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_unequal(comp_tree_t* t1,comp_tree_t* t2,comp_tree_t* t3)
{
    char* result = get_reg();
    t1->item->num_codes = t2->item->num_codes + t3->item->num_codes + 1;
    list_codes_append(t1->item->codes, list_codes_create(get_iloc_code(OP_CMP_NE,t2->item->result,t3->item->result,result)));
    t1->item->result = result;
}

void gen_if_else(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3,comp_tree_t* t4)
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

void load_array(comp_tree_t* t1){
    
    int i=0;
    
    char* result   = get_reg();
    char* reg_base = get_reg();
    char* reg_sum  = get_reg();
    
    int   base     = 0;
    char* base_str;
    
    get_iloc_code(OP_LOADI, "0", NULL, reg_base);
    
    for(i=0;i<t1->num_children;i++)
    {
        base     = cc_list_get(t1->item->sentry->bases, i)->type;
        
        get_iloc_code(OP_MULT,reg_base, tree->children[i]->result, result);
        get_iloc_code(OP_ADD, result, reg_sum, reg_sum);
    }
    snprintf(base_str, 6, "%d", t1->item->sentry->address);
    get_iloc_code(OP_LOADI, base_str, NULL, reg_base);
    get_iloc_code(OP_ADD, result, reg_sum, reg_sum);
}

