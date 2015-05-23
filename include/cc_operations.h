#ifndef __CC_OPERATIONS_H
#define __CC_OPERATIONS_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN_STR_CODE   30


#define OP_VAR             "@%s"

#define OP_ZERO            "%s"
#define OP_1SRC_1TRG       "%s %s => %s"
#define OP_2SRC_1TRG       "%s %s, %s => %s"
#define OP_1SRC_2TRG       "%s %s => %s, %s"

#define OP_0SRC_1TRG_FLOW  "%s -> %s"
#define OP_1SRC_1TRG_FLOW  "%s %s -> %s"
#define OP_2SRC_1TRG_FLOW  "%s %s, %s -> %s"
#define OP_1SRC_2TRG_FLOW  "%s %s -> %s, %s"

#define OP_REG_ESPEC_FP     "rarp"
#define OP_REG_ESPEC_RB     "rbss"

// OPERACOES INDIVIDUAIS

#define OP_NOP              0
#define OP_ADD              1
#define OP_SUB              2
#define OP_MULT             3
#define OP_DIV              4
#define OP_ADDI             5
#define OP_SUBI             6
#define OP_RSUBI            7
#define OP_MULTI            8
#define OP_DIVI             9
#define OP_RDIVI            10
#define OP_LSHIFT           11
#define OP_LSHIFTI          12
#define OP_RSHIFT           13
#define OP_RSHIFTI          14
#define OP_AND              15
#define OP_ANDI             16
#define OP_OR               17
#define OP_ORI              18
#define OP_XOR              19
#define OP_XORI             20

#define OP_LOADI            21
#define OP_LOAD             22
#define OP_LOADAI           23
#define OP_LOADAO           24
#define OP_CLOAD            122
#define OP_CLOADAI          123
#define OP_CLOADAO          124

#define OP_STORE            25
#define OP_STOREAI          26
#define OP_STOREAO          27
#define OP_CSTORE           125
#define OP_CSTOREAI         126
#define OP_CSTOREAO         127

#define OP_I2I              28
#define OP_C2C              29
#define OP_C2I              30
#define OP_I2C              31

// OPERACOES DE FLUXO DE CONTROLE  

#define OP_JUMPI            33
#define OP_JUMP             34

#define OP_CBR              35

#define OP_CMP_LT           36
#define OP_CMP_LE           37
#define OP_CMP_EQ           38
#define OP_CMP_GE           39
#define OP_CMP_GT           40
#define OP_CMP_NE           41



// OPERACOES INDIVIDUAIS - STR

#define OP_NOP_STR              "nop"
#define OP_ADD_STR              "add"
#define OP_SUB_STR              "sub"
#define OP_MULT_STR             "mult"
#define OP_DIV_STR              "div"
#define OP_ADDI_STR             "addI"
#define OP_SUBI_STR             "subI"
#define OP_RSUBI_STR            "rsubI"
#define OP_MULTI_STR            "multI"
#define OP_DIVI_STR             "divI"
#define OP_RDIVI_STR            "rdivI"
#define OP_LSHIFT_STR           "lshift"
#define OP_LSHIFTI_STR          "lshiftI"
#define OP_RSHIFT_STR           "rshift"
#define OP_RSHIFTI_STR          "rshiftI"
#define OP_AND_STR              "and"
#define OP_ANDI_STR             "andI"
#define OP_OR_STR               "or"
#define OP_ORI_STR              "orI"
#define OP_XOR_STR              "xor"
#define OP_XORI_STR             "xorI"

#define OP_LOADI_STR            "loadI"
#define OP_LOAD_STR             "load"
#define OP_LOADAI_STR           "loadAI"
#define OP_LOADAO_STR           "loadAO"
#define OP_CLOAD_STR            "cload"
#define OP_CLOADAI_STR          "cloadAI"
#define OP_CLOADAO_STR          "cloadAO"

#define OP_STORE_STR            "store"
#define OP_STOREAI_STR          "storeAI"
#define OP_STOREAO_STR          "storeAO"
#define OP_CSTORE_STR           "cstore"
#define OP_CSTOREAI_STR         "cstoreAI"
#define OP_CSTOREAO_STR         "cstoreAO"

#define OP_I2I_STR              "i2i"
#define OP_C2C_STR              "c2c"
#define OP_C2I_STR              "c2i"
#define OP_I2C_STR              "i2c"

// OPERACOES DE FLUXO DE CONTROLE - STR

#define OP_JUMPI_STR            "jumpI"
#define OP_JUMP_STR             "jump"

#define OP_CBR_STR              "cbr"

#define OP_CMP_LT_STR           "cmp_LT"
#define OP_CMP_LE_STR           "cmp_LE"
#define OP_CMP_EQ_STR           "cmp_EQ"
#define OP_CMP_GE_STR           "cmp_GE"
#define OP_CMP_GT_STR           "cmp_GT"
#define OP_CMP_NE_STR           "cmp_NE"

#define FP_INIT_ADDRESS 0
#define RP_INIT_ADDRESS 0

int offset_fp;
int offset_rb;

typedef struct iloc_code{
    
    int   op;
    
    char* reg1;
    char* reg2;
    char* result;

    char* label;
    
}iloc_code_t;


typedef struct list_codes{
    
    iloc_code_t*        item;
    struct list_codes*  next;
    
}list_codes_t;

list_codes_t* list_codes_create(iloc_code_t* item);
list_codes_t* list_codes_append(list_codes_t* list1, list_codes_t* list2);
list_codes_t* list_codes_get(list_codes_t* list, int n);

void          init_operations();
 
iloc_code_t*  get_iloc_code(int op, char* reg1, char* reg2, char* result);
char*         get_str_code(iloc_code_t* iloc_code);
 
 
int           get_address_var_fp(int size);
int           get_address_var_rb(int size);
 
iloc_code_t*  load_immediate(char* reg1, int val);
#endif
