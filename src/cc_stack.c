#include "cc_stack.h"
#include <stdio.h>

dict_stack_t* cc_stack_create(){
    
    printf("cc_stack_create()\n");

    dict_stack_t* new = (dict_stack_t*)malloc(sizeof(dict_stack_t)); 
    
    new->top = NULL;
    new->next = NULL;
    
    return new;
}
dict_stack_t* cc_stack_push(dict_stack_t* stack, dict_stack_item_t* item){
    
    printf("cc_stack_push()\n");
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
    printf("cc_stack_pop()\n");
    free(stack->top);
    return stack->next;
}
dict_stack_item_t* cc_stack_top(dict_stack_t* stack){
    printf("cc_stack_top()\n");
    return stack->top;
}
