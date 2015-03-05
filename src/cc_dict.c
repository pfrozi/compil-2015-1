#include "cc_dict.h"
#include <stdlib.h>
#include <math.h>

comp_dict_t _stable;

//Private dictionary functions

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


//sdbm
unsigned long cc_dict_sdbm(char* key)
{
    unsigned long hash = 0;
    int c;
    while (c = *key++)
        hash = c + (hash << 6) + (hash << 16) - hash;
    return hash;
}

unsigned long cc_dict_num_hash(int n)
{
    n = (pow((n >> 16),n)) * 0x45d9f3b;
    n = (pow((n >> 16),n)) * 0x45d9f3b;
    n = (pow((n >> 16),n));
    return n;
}

//djb2
unsigned long cc_dict_hash(char* key)
{
    int index;
    int i=0;
    do
    {
        index = (cc_dict_djb2(key)+i*(cc_dict_num_hash(index)+1)) % _stable.size;
        i++;
    }while(_stable.items[index]!=NULL && strcmp(key,_stable.items[index]->key)!=0);
    return index;
}

void cc_dict_resize()
{
    int newsize;
    int i;
    comp_dict_item_t** items;
    double usage = ((double)_stable.used)/_stable.size;
    //make table smaller
    if(usage<=0.25f && _stable.size>32)
    {
        newsize=_stable.size/2;
    }
    //make table bigger
    else if(usage>=0.75f)
    {
        newsize=_stable.size*2;
    }
    else
    {
        return;
    }
    items = (comp_dict_item_t**)malloc(sizeof(comp_dict_item_t*)*newsize);
    for(i=0;i<_stable.size;i++)
    {
        if(_stable.items[i]!=NULL)
        {
            int j=0;
            int index;
            do
            {
                index = (cc_dict_djb2(_stable.items[i]->key)+j*(cc_dict_num_hash(index)+1)) % newsize;
                j++;
            }while(items[index]!=NULL && strcmp(items[index]->key,_stable.items[i]->key)!=0);
            items[index] = _stable.items[i];
        }
    }
    free(_stable.items);
    _stable.items = items;
    _stable.size = newsize;
}

//Public dictionary functions
void cc_dict_init()
{
    int i;
    _stable.size  = 32;
    _stable.used  = 0;
    _stable.items = (comp_dict_item_t**)malloc(sizeof(comp_dict_item_t*)*_stable.size);
    for(i=0;i<_stable.size;i++)
    {
        _stable.items[i]=NULL;
    }
}

void cc_dict_destroy()
{
    int i=0;
    for(i=0;i<_stable.size;i++)
    {
        if(_stable.items[i]!=NULL)
        {
            free(_stable.items[i]);
        }
    }
    free(_stable.items);
}

comp_dict_item_t* cc_dict_create_item(char* key,int line)
{
    comp_dict_item_t* item = (comp_dict_item_t*)malloc(sizeof(comp_dict_item_t));
    item->key=(char*)malloc(strlen(key));
    memcpy(item->key,key,strlen(key));
    item->line=line;
    return item;
}

void cc_dict_insert(comp_dict_item_t* item)
{
    int index;
    int i=0;
    cc_dict_resize();
    do
    {
        index = (cc_dict_djb2(item->key)+i*(cc_dict_num_hash(index)+1)) % _stable.size;
        i++;
    }while(_stable.items[index]!=NULL && strcmp(item->key,_stable.items[index]->key)!=0);
    _stable.items[index]=item;
    _stable.used++;
}

void cc_dict_remove(char* key)
{
    int index;
    int i=0;
    do
    {
        index = (cc_dict_djb2(key)+i*(cc_dict_num_hash(index)+1)) % _stable.size;
        i++;
    }while(_stable.items[index]!=NULL && strcmp(key,_stable.items[index]->key)!=0);
    free(_stable.items[index]);
    _stable.items[index]=NULL;
    _stable.used--;
    cc_dict_resize();
}

comp_dict_item_t* cc_dict_get(char* key)
{
    int index;
    int i=0;
    do
    {
        index = (cc_dict_djb2(key)+i*(cc_dict_num_hash(index)+1)) % _stable.size;
        i++;
    }while(_stable.items[index]!=NULL && strcmp(key,_stable.items[index]->key)!=0);
    return _stable.items[index];
}
