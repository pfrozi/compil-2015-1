#ifndef __CC_DICT_H_
#define __CC_DICT_H_

//Struct for symbol table item
//key: key for hastable
//line: last occurence of symbol
typedef struct comp_dict_item
{
    char* key;
    int line;
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
void cc_dict_init();

//Free symboltable
void cc_dict_destroy();

//Create a new item for the symboltable
//key: key of the new item
//line: line occurence of the item
comp_dict_item_t* cc_dict_create_item(char* key,int line);

//Insert a new item inti the symboltable
void cc_dict_insert(comp_dict_item_t* item);

//Remove an item from the symboltable
//key:key to remove from symboltable
void cc_dict_remove(char* key);

//Get an item from the symboltable
//key: Key of the item
comp_dict_item_t* cc_dict_get(char* key);

#endif
