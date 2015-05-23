#include "cc_gencode.h" 

void literal(comp_tree_t* t)
{
    if(t->item->type==IKS_INT)
    {
        int val = t->item->sentry->val_int;
        char* reg1 = (char*)malloc(sizeof(char)*8);
        get_iloc_code(OP_LOADI,reg1, NULL, get_reg());
    }
}
