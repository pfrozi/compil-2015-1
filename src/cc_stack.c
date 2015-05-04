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