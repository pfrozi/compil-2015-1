#ifndef __CC_DICT_H_
#define __CC_DICT_H_

#include <stdbool.h>
#include "cc_list.h"

#define SCOPE_TYPE_GLOBAL 0
#define SCOPE_TYPE_LOCAL  1

struct comp_dict_item;

typedef struct comp_dict_item_key
{
    char* lexem;
    int   type;
}comp_dict_item_key_t;

//Struct for symbol table item
//key: key for hastable
//line: last occurence of symbol
typedef struct comp_dict_item
{
    comp_dict_item_key_t key;
    int line;
    int type;
        
    int iks_type;
    int iks_type2;
    int iks_var;
    int iks_size;
    
    comp_list_t* bases;
    int dimension;
    
    int scope_type;
    
    int address;
    
    comp_list_t* iks_arguments;
    union
    {
        int val_int;
        float val_float;
        char val_char;
        bool val_bool;
        char* val_str;
        char* ident;
    };
}comp_dict_item_t;

//Struct for symbol table
//size: current size of hashtable
//used: used places in hashtable
//items: values
typedef struct comp_dict
{
    int size;
    int used;
    comp_dict_item_t** items;
}comp_dict_t;

//Initialize symboltable
void cc_dict_init(comp_dict_t* table);

//Free symboltable
void cc_dict_destroy(comp_dict_t* table);

//Create a new key
//lexem: lexem of scanner
//type: type of lexem
comp_dict_item_key_t cc_dict_create_item_key(char* lexem, int type);

//Create a new item for the symboltable
//key: key of the new item
//line: line occurence of the item
comp_dict_item_t* cc_dict_create_item(comp_dict_item_key_t key,int line);

//Insert a new item inti the symboltable
comp_dict_item_t* cc_dict_insert(comp_dict_t* table,comp_dict_item_t* item);

//Remove an item from the symboltable
//key:key to remove from symboltable
void cc_dict_remove(comp_dict_t* table,comp_dict_item_key_t key);

//Get an item from the symboltable
//key: Key of the item
comp_dict_item_t* cc_dict_get(comp_dict_t* table,comp_dict_item_key_t key);

#endif
