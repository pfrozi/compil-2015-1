#include "cc_gencode.h" 
#include "cc_regs.h"
#include "cc_rot.h"


void gen_literal(comp_tree_t* t)
{
    
    if(t->item->iks_type==IKS_INT)
    {
    	t->item->num_codes=1;
        int val = t->item->sentry->val_int;
        char* result = (char*)get_reg();
        
        iloc_code_t* code = load_immediate(result, val);
        t->item->codes = list_codes_create(code);
        t->item->result = result;
    }
    else if(t->item->iks_type==IKS_BOOL)
    {
    	t->item->num_codes=1;
        int val = t->item->sentry->val_int;
        char* result = (char*)get_reg();
        iloc_code_t* code = NULL;
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
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_ADD,result1,result2,result,NULL)));
    
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
        
}

void gen_sub(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_SUB,result1,result2,result,NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
}

void gen_mul(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_MULT,result1,result2,result,NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
}

void gen_div(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_DIV,result1,result2,result,NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
}

void gen_and(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    /*   
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_AND,result1, result2, result,NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    */
    
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* rotN   = (char*)get_rot();
    
    char* result = result2;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result2, t1->item->bv, t1->item->bf, NULL)));
        
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, rotN)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result1, rotN, t1->item->bf, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
    // set result
    t1->item->result = result;
}

void gen_or(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    /*
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_OR,result1, result2, result,NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
                                      
    */
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* rotN   = (char*)get_rot();
    
    char* result = result2;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result2, t1->item->bv, t1->item->bf, NULL)));
        
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, rotN)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result1, t1->item->bv, rotN, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
    // set result
    t1->item->result = result;
}

void gen_xor(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    char* result = (char*)get_reg();
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_XOR,result1, result2, result,NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
}

void gen_less(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = (char*)get_reg();
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CMP_LT, result1, result2, result, NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
    
    
}

void gen_greater(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = (char*)get_reg();
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CMP_GT, result1, result2, result, NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
}

void gen_less_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = (char*)get_reg();
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CMP_LE, result1, result2, result, NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
}

void gen_greater_equal(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = (char*)get_reg();
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CMP_GE, result1, result2, result, NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
}

void gen_equal(comp_tree_t* t1,comp_tree_t* t2, comp_tree_t* t3)
{
    char* result = (char*)get_reg();
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CMP_EQ, result1, result2, result, NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
}

void gen_unequal(comp_tree_t* t1,comp_tree_t* t2,comp_tree_t* t3)
{
    char* result = (char*)get_reg();
    
    char* result1 = t2->item->result;
    char* result2 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CMP_NE, result1, result2, result, NULL)));
    
    // set result
    t1->item->result = result;
    
    // make the append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
}

void gen_if(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    
    char* result1 = t2->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t1->item->next)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t2->item->bv)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result1, t1->item->bv, t1->item->next, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
    
}

void gen_if_else(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3,comp_tree_t* t4)
{
    char* result1 = t2->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t1->item->next)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t4->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t2->item->bf)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_JUMPI, NULL, NULL, t1->item->next, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t2->item->bv)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result1, t1->item->bv, t1->item->bf, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
}

void gen_do_while(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    char* result1 = t3->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t1->item->next)));
       
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result1, t1->item->begin, t1->item->next, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t1->item->begin)));
    
}

void gen_while_do(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3)
{
    
    char* result1 = t2->item->result;
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t1->item->next)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_JUMPI, NULL, NULL, t1->item->begin, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t2->item->bv)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_CBR, result1, t2->item->bv, t1->item->next, NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t2->item->codes);
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_NOP, NULL, NULL, NULL, t1->item->begin)));
    
    
    
}

void gen_int_invert(comp_tree_t* t1)
{

}

void save_ident(comp_tree_t* t1)
{
}

void load_ident(comp_tree_t* t1)
{
    if(t1->item->sentry->iks_var == IKS_VARIABLE && t1->item->sentry->iks_type!=IKS_NULL)
    {
        char* result = (char*)get_reg();
        char* offset = (char*)malloc(sizeof(char)*8);
        
        fprintf(stderr,"SENTRY: %s\n",t1->item->sentry->key.lexem);
        sprintf(offset,"%d",t1->item->sentry->address);
        
        if(t1->item->sentry->scope_type == SCOPE_TYPE_LOCAL)
        {
            t1->item->codes = list_codes_create(get_iloc_code(OP_LOADAI,OP_REG_ESPEC_FP,offset,result,NULL));
        }
        else
        {
            t1->item->codes = list_codes_create(get_iloc_code(OP_LOADAI,OP_REG_ESPEC_RB,offset,result,NULL));
        }
        
        // set result
        t1->item->result = result;
    }
}

void gen_atrib_ident(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3){
    
    char* result = t3->item->result;
    
    char* r_offs =  (char*)malloc(sizeof(char)*10);
    
    snprintf(r_offs, 10, "%d", t2->item->sentry->address);
    
    if(t2->item->sentry->scope_type == SCOPE_TYPE_LOCAL)
    {
        t1->item->codes = list_codes_create(get_iloc_code(OP_STOREAI,result,OP_REG_ESPEC_FP,r_offs,NULL));
    }
    else
    {
        t1->item->codes = list_codes_create(get_iloc_code(OP_STOREAI,result,OP_REG_ESPEC_RB,r_offs,NULL));
    }
    
    // set result
    t1->item->result = result;
    
    // make the append
    // obs: If ident, don't append the code of t2
    if(t2->item->type != AST_IDENTIFICADOR){
        list_codes_append(t1->item->codes
                        , t2->item->codes);
    }
    
    list_codes_append(t1->item->codes
                    , t3->item->codes);
    
}

void gen_atrib_array(comp_tree_t* t1, comp_tree_t* t2, comp_tree_t* t3){
    
    char* offset      = (char*)get_reg();
    char* offset_aux  = (char*)get_reg();
    char* offset_init = (char*)malloc(sizeof(char)*8);
    char* c_size      = (char*)malloc(sizeof(char)*8);

    comp_tree_t* ident = t2->children[0];
    
    char* result = t3->item->result;
    
    int size = define_type_size(ident->item->sentry->iks_type);
    
    // set init offset
    sprintf(offset_init,"%d",ident->item->sentry->address);
    sprintf(c_size,"%d", size);
    
    fprintf(stderr,"make storage\n");
    if(ident->item->sentry->scope_type == SCOPE_TYPE_LOCAL)
    {
        t1->item->codes = list_codes_create(get_iloc_code(OP_STOREAO,result,OP_REG_ESPEC_FP,offset,NULL));
    }
    else
    {
        t1->item->codes = list_codes_create(get_iloc_code(OP_STOREAO,result,OP_REG_ESPEC_RB,offset,NULL));
    }
    
    fprintf(stderr,"make add_off\n");
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_ADDI, offset, offset_init, offset,NULL)));
    
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(get_iloc_code(OP_MULTI, offset, c_size, offset, NULL)));
    
    fprintf(stderr,"make load\n");
    //load_array_addr(t2, 1, offset, offset_aux, t1->item->codes);
    t1->item->codes = load_array_addr2(t2, t2->children[1], 0, offset, offset_aux, t1->item->codes);
    
    fprintf(stderr,"make children\n");
    // init offset zero
    t1->item->codes = list_codes_append(t1->item->codes
                                      , list_codes_create(load_immediate(offset, 0)));
    
    fprintf(stderr,"append children\n");
    append_children(t2, 1, t1->item->codes);
    
    // set result 
    t1->item->result = result;
    
    //make append
    t1->item->codes = list_codes_append(t1->item->codes
                                      , t3->item->codes);
    
    
}

void load_array(comp_tree_t* t1){
    
    comp_tree_t* ident = t1->children[0];
    
    if(ident->item->sentry->iks_var == IKS_ARRAY && ident->item->sentry->iks_type!=IKS_NULL)
    {
        char* result      = (char*)get_reg();
        char* offset      = (char*)get_reg();
        char* offset_aux  = (char*)get_reg();
        char* offset_init = (char*)malloc(sizeof(char)*8);
        char* c_size      = (char*)malloc(sizeof(char)*8);
        
        int size = define_type_size(ident->item->sentry->iks_type);
        
        // set init offset
        sprintf(offset_init,"%d",ident->item->sentry->address);
        sprintf(c_size,"%d", size);
        
        if(ident->item->sentry->scope_type == SCOPE_TYPE_LOCAL)
        {
            t1->item->codes = list_codes_append(t1->item->codes
                                              , list_codes_create(get_iloc_code(OP_LOADAO,OP_REG_ESPEC_FP,offset,result,NULL)));
        }
        else
        {
            t1->item->codes = list_codes_append(t1->item->codes
                                              , list_codes_create(get_iloc_code(OP_LOADAO,OP_REG_ESPEC_RB,offset,result,NULL)));
        }
        
        t1->item->codes = list_codes_append(t1->item->codes
                                          , list_codes_create(get_iloc_code(OP_ADDI, offset, offset_init, offset,NULL)));
        
        t1->item->codes = list_codes_append(t1->item->codes
                                          , list_codes_create(get_iloc_code(OP_MULTI, offset, c_size, offset, NULL)));
        
        //load_array_addr(t1, 1, offset, offset_aux, t1->item->codes);
        t1->item->codes = load_array_addr2(t1, t1->children[1], 0, offset, offset_aux, t1->item->codes);
        
        // init offset zero
        t1->item->codes = list_codes_append(t1->item->codes
                                          , list_codes_create(load_immediate(offset, 0)));
        
        // set result 
        t1->item->result = result;
        
        //make append
        //append_children(t1,1, t1->item->codes);
        
    }
}

list_codes_t* load_array_addr2(comp_tree_t* parent, comp_tree_t* child, int depth, char* reg_result, char* reg_aux, list_codes_t* append){
    
    comp_tree_t* next_child = NULL;
    int dim                 = parent->children[0]->item->sentry->dimension;
    
    fprintf(stderr,"Depth: %d Dimension-1: %d\n", depth,dim-1);
    
    if(depth < dim-1){
        
        next_child = child->children[child->num_children-1];
        
        append = load_array_addr2(parent, next_child, depth+1, reg_result, reg_aux, append);
        
        int base            = cc_list_get(parent->children[0]->item->sentry->bases, depth)->type;
        char* c_base        = (char*)malloc(sizeof(char)*8);
        sprintf(c_base,"%d",base);
        
        append = list_codes_append(append
                                 , list_codes_create(get_iloc_code(OP_ADD, reg_aux, child->item->result, reg_result,NULL)));

        append = list_codes_append(append
                                 , list_codes_create(get_iloc_code(OP_MULTI, reg_result, c_base, reg_aux,NULL)));
        
    }else{
        
        fprintf(stderr,"Depth: %d result: %s\n", depth,child->item->result);
        append = list_codes_append(append
                                 , list_codes_create(get_iloc_code(OP_ADD, reg_result, child->item->result, reg_result,NULL)));
    }
    
    //append = list_codes_append(append
    //                        , child->item->codes);
    return append;
    
}

void load_array_addr(comp_tree_t* parent, int i, char* reg_result, char* reg_aux, list_codes_t* append){
   
    int child = i-1;
    fprintf(stderr,"FILHOS: %d\n", parent->num_children);
    if(parent->children[1]!=NULL)fprintf(stderr,"FILHOS 1: %d\n", parent->children[1]->item->sentry->val_int);
    if(parent->children[1]!=NULL && parent->children[1]->children[0]!=NULL)fprintf(stderr,"FILHOS 2: %d\n", parent->children[1]->children[0]->item->sentry->val_int);
    
    if(parent->children[i+1]!=NULL){
        
        fprintf(stderr,"load_array_addr init %d\n", i);
        
        load_array_addr(parent, ++i, reg_result, reg_aux, append);
         
        int base            = cc_list_get(parent->item->sentry->bases, child)->type;
        char* c_base        = (char*)malloc(sizeof(char)*8);

        sprintf(c_base,"%d",base);

        append = list_codes_append(append
                                 , list_codes_create(get_iloc_code(OP_ADD, reg_aux, parent->children[i+1]->item->result, reg_result,NULL)));

        append = list_codes_append(append
                                 , list_codes_create(get_iloc_code(OP_MULTI, parent->children[i]->item->result, c_base, reg_aux,NULL)));
                
    }
    if(child==0){
        append = list_codes_append(append
                                 , list_codes_create(get_iloc_code(OP_ADD, reg_result, parent->children[i]->item->result, reg_result,NULL)));        
    }
}

void append_children(comp_tree_t* parent, int child, list_codes_t* append){
 
    if(parent->children[child+1]!=NULL){
        fprintf(stderr,"make children %d\n", child);
        append_children(parent, ++child, append);
    }
    
    append = list_codes_append(append
                             , parent->children[child]->item->codes);
}
