#include "cc_dict.h"
#include "main.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Private dictionary functions

//djb2 hashing for strings
unsigned long cc_dict_djb2(char* key)
{
    unsigned long h = 5381;
    int c;
    while(c = *key++)
    {
        h = ((h << 5) + h) + c;
    }
    return h;
}

long pow2(int b,int n)
{
    int ret=b;
    int i=1;
    for(i;i<n;i++)
    {
        ret=ret*b;
    }
    return ret;
}

//hash function for double hashing
unsigned long cc_dict_num_hash(int n)
{
    n = (pow2((n >> 16),n)) * 0x45d9f3b;
    n = (pow2((n >> 16),n)) * 0x45d9f3b;
    n = (pow2((n >> 16),n));
    return n;
}

//Function to resize size of hashtable for better performance
void cc_dict_resize(comp_dict_t* table)
{
    int newsize;
    int i;
    comp_dict_item_t** items;
    double usage = ((double)((*table).used))/(*table).size;
    //make table smaller
    //when less then 25% of places are occupied
    if(usage<=0.25f && (*table).size>32)
    {
        newsize=(*table).size/2;
    }
    //make table bigger
    //when more then 75% of places are occupied
    else if(usage>=0.75f)
    {
        newsize=(*table).size*2;
    }
    //Do nothing
    else
    {
        return;
    }
    //create new array with new size
    items = (comp_dict_item_t**)malloc(sizeof(comp_dict_item_t*)*newsize);

    //Rehash items for the new table
    for(i=0;i<(*table).size;i++)
    {
        //Just do this, when place is occupied
        if((*table).items[i]!=NULL)
        {
            int j=0;
            int index;
            do
            {
                index = (cc_dict_djb2((*table).items[i]->key.lexem)+j*(cc_dict_num_hash(index)+1)) % newsize;
                j++;
            }while(items[index]!=NULL && strcmp(items[index]->key.lexem,(*table).items[i]->key.lexem)!=0);
            items[index] = (*table).items[i];
        }
    }
    //Free old table and point to new table
    free((*table).items);
    (*table).items = items;
    (*table).size = newsize;
}

//Public dictionary functions

//Init symboltable
//initial size of the symboltable is 32 entries
void cc_dict_init(comp_dict_t* table)
{
    int i;
    (*table).size  = 32;
    (*table).used  = 0;
    (*table).items = (comp_dict_item_t**)malloc(sizeof(comp_dict_item_t*)*((*table).size));
    //mark all places as not occupied
    for(i=0;i<(*table).size;i++)
    {
        (*table).items[i]=NULL;
    }
}

//Free items in hashtable
void cc_dict_destroy(comp_dict_t* table)
{
    int i=0;
    for(i=0;i<(*table).size;i++)
    {
        if((*table).items[i]!=NULL)
        {
            if((*table).items[i]->type==SIMBOLO_LITERAL_STRING)
            {
                free((*table).items[i]->val_str);
            }
            else if((*table).items[i]->type==SIMBOLO_IDENTIFICADOR)
            {
                free((*table).items[i]->ident);
            }
            free((*table).items[i]->key.lexem);
            free((*table).items[i]);
        }
    }
    free((*table).items);
}

//Create a new key
comp_dict_item_key_t cc_dict_create_item_key(char* lexem, int type)
{
    comp_dict_item_key_t key;
    key.lexem=(char*)malloc(sizeof(char)*strlen(lexem)+1);
    strcpy(key.lexem,lexem);
    key.type=type;
    return key;
}

//Create a new symboltable entry
comp_dict_item_t* cc_dict_create_item(comp_dict_item_key_t key,int line)
{
    comp_dict_item_t* item = (comp_dict_item_t*)malloc(sizeof(comp_dict_item_t));
    item->key=key;
    item->line=line;
    item->ident=NULL;
    item->val_str=NULL;
    return item;
}

//Insert an item into the symboltable
//Collision behaviour is double hashing
//and eventually resize table
comp_dict_item_t* cc_dict_insert(comp_dict_t* table,comp_dict_item_t* item)
{
    int index=0;
    int i=0;
    cc_dict_resize(table);
    do
    {
        index = (cc_dict_djb2(item->key.lexem)+i*(cc_dict_num_hash(index)+1)) % (*table).size;
        i++;
    }while((*table).items[index]!=NULL && strcmp(item->key.lexem,(*table).items[index]->key.lexem)!=0);
    (*table).items[index]=item;
    (*table).used++;
    return item;
}

//Remove an item into the symboltable
//Collision behaviour is double hashing
//and eventually resize table
void cc_dict_remove(comp_dict_t* table,comp_dict_item_key_t key)
{
    int index=0;
    int i=0;
    do
    {
        index = (cc_dict_djb2(key.lexem)+i*(cc_dict_num_hash(index)+1)) % (*table).size;
        i++;
    }while((*table).items[index]!=NULL && strcmp(key.lexem,(*table).items[index]->key.lexem)!=0);
    free((*table).items[index]);
    (*table).items[index]=NULL;
    (*table).used--;
    cc_dict_resize(table);
}

//Get an item with the specified key or NULL,
//when an empty place is found
//Collision behaviour is double hashing
comp_dict_item_t* cc_dict_get(comp_dict_t* table,comp_dict_item_key_t key)
{
    int index=0;
    int i=0;
    do
    {
        index = (cc_dict_djb2(key.lexem)+i*(cc_dict_num_hash(index)+1)) % (*table).size;
        i++;
    }while((*table).items[index]!=NULL && strcmp(key.lexem,(*table).items[index]->key.lexem)!=0);
    return (*table).items[index];
}

int define_type_size(int type){
    
    switch(type){

        //case IKS_NULL  :  return IKS_NULL_SIZE;
        case IKS_INT   :  return IKS_INT_SIZE;
        case IKS_FLOAT :  return IKS_FLOAT_SIZE;
        case IKS_CHAR  :  return IKS_CHAR_SIZE;
        case IKS_STRING:  return IKS_STRING_SIZE;
        case IKS_BOOL  :  return IKS_BOOL_SIZE; 
    }
}

int get_args_size(comp_dict_item_t* sentry){
    
    int size = 0;
    
    comp_list_t* l = sentry->iks_arguments;
    
    while(l!=NULL){
        size += define_type_size(l->type);
        l = l->next;
    }
    
    return size;
}
