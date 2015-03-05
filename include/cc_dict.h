#ifndef __CC_DICT_H_
#define __CC_DICT_H_
typedef struct comp_dict_item
{
    char* key;
    int line;
}comp_dict_item_t;

typedef struct comp_dict
{
    int size;
    int used;
    comp_dict_item_t** items;
}comp_dict_t;

void cc_dict_init();
void cc_dict_destroy();
comp_dict_item_t* cc_dict_create_item(char* key,int line);
void cc_dict_insert(comp_dict_item_t* item);
void cc_dict_remove(char* key);
comp_dict_item_t* cc_dict_get(char* key);

#endif
