#ifndef __CC_STACK_H_
#define __CC_STACK_H_

#include <stdlib.h>
#include "cc_dict.h"

typedef struct dict_stack_item
{
    comp_dict_t* item;
}dict_stack_item_t;


typedef struct dict_stack
{
    dict_stack_item_t*      top;
    struct dict_stack*      next;
}dict_stack_t;

dict_stack_t* cc_stack_create();
dict_stack_t* cc_stack_push(dict_stack_t* stack);
dict_stack_t* cc_stack_pop(dict_stack_t* stack);
dict_stack_item_t* cc_stack_top(dict_stack_t* stack);

comp_dict_item_t* cc_stack_find_top(dict_stack_t* stack, comp_dict_item_t* item);
dict_stack_t* cc_stack_add_top(dict_stack_t* stack, comp_dict_item_t* item);
#endif