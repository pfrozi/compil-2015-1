#include "cc_gencode.h" 

void literal(comp_tree_t* t)
{
    if(t->item->type==IKS_INT)
    {
    	t->num_codes=1;
    	t->codes = (iloc_code_t**)malloc(sizeof(iloc_code_t*));
        int val = t->item->sentry->val_int;
        char* reg1 = (char*)malloc(sizeof(char)*8);
        char* result = get_reg();
        char* code = get_iloc_code(OP_LOADI,reg1, NULL, result);
        t->codes[0] = code;
    }
}

void add(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void sub(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void mul(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void div(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
}

void int_invert(comp_tree_t* t1)
{
}
