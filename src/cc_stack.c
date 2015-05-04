#include "cc_stack.h"
#include <stdio.h>

dict_stack_t* cc_stack_create(){
    
    printf("cc_stack_create()\n");
    
    // create a global scope
    return cc_stack_push(NULL);
}
dict_stack_t* cc_stack_push(dict_stack_t* stack){
    
    printf("cc_stack_push()\n");
    
    dict_stack_t* new = (dict_stack_t*)malloc(sizeof(dict_stack_t)); 
    
    new->top = (dict_stack_item_t*)malloc(sizeof(dict_stack_item_t));
    new->top->item = (comp_dict_t*)malloc(sizeof(comp_dict_t));
    cc_dict_init(new->top->item);
    
    new->next = stack;
    
    return new;
}
dict_stack_t* cc_stack_pop(dict_stack_t* stack){
    printf("cc_stack_pop()\n");
    
    dict_stack_t* new = stack->next;
    
    free(stack->top->item);
    free(stack->top);
    free(stack);
    return new;
    
}
dict_stack_item_t* cc_stack_top(dict_stack_t* stack){
    printf("cc_stack_top()\n");
    return stack->top;
}

comp_dict_item_t* cc_stack_find_top(dict_stack_t* stack, comp_dict_item_t* item){
    
    comp_dict_item_t* item_scope = NULL;
    
    if(stack->top!=NULL){
        item_scope = cc_dict_get(stack->top->item, item->key);
    }
    
    return item_scope;
}

dict_stack_t* cc_stack_add_top(dict_stack_t* stack, comp_dict_item_t* item){
    
    if(stack->top!=NULL){
        comp_dict_item_t* new_item = NULL;
        
        comp_dict_item_key_t key = cc_dict_create_item_key(item->key.lexem, 0);
        new_item = cc_dict_insert(stack->top->item,cc_dict_create_item(key, item->line));
        
        new_item->iks_type = item->iks_type;
        new_item->iks_var  = item->iks_var;
    }
    
    return stack;
}