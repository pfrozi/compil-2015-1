#include "cc_stack.h"

dict_stack_t* cc_stack_create(){
    
    dict_stack_t* new = (dict_stack_t*)malloc(sizeof(dict_stack_t)); 
    
    new->top = NULL;
    new->next = NULL;
    
    return new;
}
dict_stack_t* cc_stack_push(dict_stack_t* stack, dict_stack_item_t* item){
    
    dict_stack_t* new = (dict_stack_t*)malloc(sizeof(dict_stack_t)); 
    new->top = item;
    
    if(stack->top!=NULL){
        
        new->next = stack;
    }else
    {
        free(stack);
        new->next = NULL;
    }
    return new;
}
dict_stack_t* cc_stack_pop(dict_stack_t* stack){
    
    free(stack->top);
    return stack->next;
}
dict_stack_item_t* cc_stack_top(dict_stack_t* stack){
    
    return stack->top;
}

comp_dict_item_t* cc_stack_find_top(dict_stack_t* stack, comp_dict_item_t* item){
    
    comp_dict_item_t* item_scope = NULL;
    
    if(stack->top!=NULL){
        item_scope = cc_dict_get(stack->top, item->key);
    }
    
    return item_scope;
}