#include "cc_operations.h"

iloc_code_t* get_iloc_code(int op, char* reg1, char* reg2, char* result, char* label){

    iloc_code_t* new_code;
    
    new_code = (iloc_code_t*)malloc(sizeof(iloc_code_t));
    
    new_code->op     = op;
    new_code->reg1   = reg1;
    new_code->reg2   = reg2;
    new_code->result = result;
    new_code->label  = label;
    
    return new_code;
}
char* get_str_code(iloc_code_t* iloc_code){

    char* ret;
    char* op_code;
    
    ret = (char*)malloc(sizeof(char)*MAX_LEN_STR_CODE);
    
    if(iloc_code->label!=NULL){
        
        snprintf(ret
                , MAX_LEN_STR_CODE
                , OP_LABEL
                , iloc_code->label);
    }
    else{
        
        switch(iloc_code->op){

            case OP_ADD    : op_code = OP_ADD_STR; break;
            case OP_SUB    : op_code = OP_SUB_STR; break; 
            case OP_MULT   : op_code = OP_MULT_STR; break;
            case OP_DIV    : op_code = OP_DIV_STR; break;
            case OP_ADDI   : op_code = OP_ADDI_STR; break;
            case OP_SUBI   : op_code = OP_SUBI_STR; break;
            case OP_RSUBI  : op_code = OP_RSUBI_STR; break;
            case OP_MULTI  : op_code = OP_MULTI_STR; break;
            case OP_DIVI   : op_code = OP_DIVI_STR; break;
            case OP_RDIVI  : op_code = OP_RDIVI_STR; break;
            case OP_LSHIFT : op_code = OP_LSHIFT_STR; break;
            case OP_LSHIFTI: op_code = OP_LSHIFTI_STR; break;
            case OP_RSHIFT : op_code = OP_RSHIFT_STR; break;
            case OP_RSHIFTI: op_code = OP_RSHIFTI_STR; break;
            case OP_AND    : op_code = OP_AND_STR; break;
            case OP_ANDI   : op_code = OP_ANDI_STR; break;
            case OP_OR     : op_code = OP_OR_STR; break;
            case OP_ORI    : op_code = OP_ORI_STR; break;
            case OP_XOR    : op_code = OP_XOR_STR; break;
            case OP_XORI   : op_code = OP_XORI_STR; break;
            case OP_LOADAI : op_code = OP_LOADAI_STR; break;
            case OP_LOADAO : op_code = OP_LOADAO_STR; break;
            case OP_CLOADAI: op_code = OP_CLOADAI_STR; break;
            case OP_CLOADAO: op_code = OP_CLOADAO_STR; break;
            case OP_CMP_LT : op_code = OP_CMP_LT_STR; break;
            case OP_CMP_LE : op_code = OP_CMP_LE_STR; break;
            case OP_CMP_EQ : op_code = OP_CMP_EQ_STR; break;
            case OP_CMP_GE : op_code = OP_CMP_GE_STR; break;
            case OP_CMP_GT : op_code = OP_CMP_GT_STR; break;
            case OP_CMP_NE : op_code = OP_CMP_NE_STR; break;
            case OP_STOREAI : op_code = OP_STOREAI_STR; break;
            case OP_STOREAO : op_code = OP_STOREAO_STR; break;
            case OP_CSTOREAI: op_code = OP_CSTOREAI_STR; break;
            case OP_CSTOREAO: op_code = OP_CSTOREAO_STR; break;
            case OP_CBR     : op_code = OP_CBR_STR; break;
            case OP_LOADI : op_code = OP_LOADI_STR; break;
            case OP_LOAD  : op_code = OP_LOAD_STR; break;
            case OP_CLOAD : op_code = OP_CLOAD_STR; break;
            case OP_STORE : op_code = OP_STORE_STR; break;
            case OP_CSTORE: op_code = OP_CSTORE_STR; break;
            case OP_I2I   : op_code = OP_I2I_STR; break;
            case OP_C2C   : op_code = OP_C2C_STR; break;
            case OP_C2I   : op_code = OP_C2I_STR; break;
            case OP_I2C   : op_code = OP_I2C_STR; break;
            case OP_JUMPI  : op_code = OP_JUMPI_STR; break;
            case OP_JUMP   : op_code = OP_JUMP_STR; break;

        }
        
        switch(iloc_code->op){

            case OP_ADD    :
            case OP_SUB    :
            case OP_MULT   :
            case OP_DIV    :
            case OP_ADDI   :
            case OP_SUBI   :
            case OP_RSUBI  :
            case OP_MULTI  :
            case OP_DIVI   :
            case OP_RDIVI  :
            case OP_LSHIFT :
            case OP_LSHIFTI:
            case OP_RSHIFT :
            case OP_RSHIFTI:
            case OP_AND    :
            case OP_ANDI   :
            case OP_OR     :
            case OP_ORI    :
            case OP_XOR    :
            case OP_XORI   :
            case OP_LOADAI :
            case OP_LOADAO :
            case OP_CLOADAI:
            case OP_CLOADAO:
            {
                snprintf(ret
                        , MAX_LEN_STR_CODE
                        , OP_2SRC_1TRG
                        , op_code, iloc_code->reg1, iloc_code->reg2, iloc_code->result);
                break;
            }
            case OP_CMP_LT :
            case OP_CMP_LE :
            case OP_CMP_EQ :
            case OP_CMP_GE :
            case OP_CMP_GT :
            case OP_CMP_NE :
            {
                snprintf(ret
                        , MAX_LEN_STR_CODE
                        , OP_2SRC_1TRG_FLOW
                        , op_code, iloc_code->reg1, iloc_code->reg2, iloc_code->result);
                break;
            }

            case OP_STOREAI : 
            case OP_STOREAO : 
            case OP_CSTOREAI: 
            case OP_CSTOREAO: 
            {
                snprintf(ret
                        , MAX_LEN_STR_CODE
                        , OP_1SRC_2TRG
                        , op_code, iloc_code->reg1, iloc_code->reg2, iloc_code->result);
                break;
            }
            case OP_CBR     :
            {
                snprintf(ret
                        , MAX_LEN_STR_CODE
                        , OP_1SRC_2TRG_FLOW
                        , op_code, iloc_code->reg1, iloc_code->reg2, iloc_code->result);
                break;
            }

            case OP_LOADI : 
            case OP_LOAD  : 
            case OP_CLOAD : 
            case OP_STORE : 
            case OP_CSTORE: 
            case OP_I2I   : 
            case OP_C2C   : 
            case OP_C2I   : 
            case OP_I2C   : 
            {
                snprintf(ret
                        , MAX_LEN_STR_CODE
                        , OP_1SRC_1TRG
                        , op_code, iloc_code->reg1, iloc_code->result);
                break;
            }
            case OP_JUMPI  : 
            case OP_JUMP   : 
            {
                snprintf(ret
                        , MAX_LEN_STR_CODE
                        , OP_0SRC_1TRG_FLOW
                        , op_code, iloc_code->result);
                break;
            }

        }
    }
    return ret;
}


void init_operations(){

    offset_fp = FP_INIT_ADDRESS;
    offset_rb = RP_INIT_ADDRESS;
    
    memory_pointer = 0;
}

void fp_reset(){
    
    offset_fp = FP_INIT_ADDRESS;
}

void set_main_rot(char* rot){

    main_rot = rot;
}

int get_address_var_fp(int size){

    int address = offset_fp;
    offset_fp  += size;
    
    return address;
}
int get_address_var_rb(int size){

    int address = offset_rb;
    offset_rb  += size;
    
    return address;
}

iloc_code_t*  load_immediate(char* reg1, int val){
    
    char* base_str;
    
    base_str = (char*)malloc(sizeof(char)*10);
    
    snprintf(base_str, 10, "%d", val);
    return get_iloc_code(OP_LOADI, base_str, NULL, reg1,NULL);
}


list_codes_t* list_codes_create(iloc_code_t* item){

    list_codes_t* list = (list_codes_t*)malloc(sizeof(list_codes_t));
    list->item = item;
    list->next = NULL;
    return list;
}

list_codes_t* list_codes_append(list_codes_t* list1, list_codes_t* list2){
    
    if(list1!=NULL && list2!=NULL)
    {
    	list_codes_t *l = list1;
    	while(l->next!=NULL)
    	{
    	    l=l->next;
    	};
    	l->next = list2;
    }else if(list1==NULL){
        
        list1 = list2;
    }
    return list1;
}

list_codes_t* list_codes_get(list_codes_t* list, int n){

    int i=0;
    list_codes_t *l = list;
    do
    {
        l=l->next;
        i++;
    }while(i!=n && l!=NULL);
    return l;
}

int get_addr_pos(list_codes_t* list){
    
    int cont=0;
    list_codes_t *l = list;
    do
    {   
        if(l->item->label==NULL) cont++;
        l=l->next;
    }while(l!=NULL);
    
    return cont-1;
}