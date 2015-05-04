#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_ast.h"
#include <stdlib.h>

comp_tree_t* ast;
comp_dict_t* stable;

dict_stack_t* scopes;

//return the current line number
//incremented in scanner.l after
//every encontred newline

int getLineNumber (void)
{
  return line_number;
}

void yyerror (char const *mensagem)
{
  fprintf (stderr, "Error(%d): %s\n",line_number, mensagem); //altere para que apareça a linha
}

int yyerror_var(comp_dict_item_t* sentry){
    
    if(sentry->iks_var==IKS_VARIABLE){
        
        return IKS_ERROR_VARIABLE;
    }
    else if(sentry->iks_var==IKS_ARRAY){
    
        return IKS_ERROR_VECTOR;
    }
    else if(sentry->iks_var==IKS_FUNCTION){
    
        return IKS_ERROR_FUNCTION;
    }
    
}

void main_init (int argc, char **argv)
{
  //implemente esta função com rotinas de inicialização, se necessário
  stable = (comp_dict_t*)malloc(sizeof(comp_dict_t));
  cc_dict_init(stable);
    
  scopes = cc_stack_create();
    
}

void main_finalize (void)
{
  //implemente esta função com rotinas de inicialização, se necessário
  cc_dict_destroy(stable);
  //cc_tree_destroy_node(ast);
  free(stable);
  
  scopes = cc_stack_pop(scopes);
}

comp_dict_item_t* yystack_find_top(comp_dict_item_t* sentry){
        
    printf(" yystack_find_top(): %s\n", sentry->key.lexem);
    
    comp_dict_item_t* item = cc_stack_find_top(scopes, sentry);
    return item;
}
comp_dict_item_t* yystack_find(comp_dict_item_t* sentry){
        
    printf(" yystack_find(): %s\n", sentry->key.lexem);
    
    comp_dict_item_t* item = cc_stack_find(scopes, sentry);
    return item;
}
void yystack_add(comp_dict_item_t* sentry, int iks_type, int iks_var){
    
    printf(" yystack_add()\n");
    
    sentry->iks_type = iks_type;
    sentry->iks_var = iks_var;
    
    scopes = cc_stack_add_top(scopes, sentry);
}
void yystack_update_var(comp_dict_item_t* sentry, int var){
    
    yystack_find(sentry)->iks_var = var;
    cc_dict_get(stable, sentry->key)->iks_var = var;
    
}

int yystack_verify_types(int type_a, int type_b){
    
    printf("\ttipo a: %d\t\ttipo b: %d", type_a, type_b);
    
    if(type_a != IKS_STRING && type_b == IKS_STRING){
       return IKS_ERROR_STRING_TO_X;
    }
    if(type_a != IKS_CHAR && type_b == IKS_CHAR){
       return IKS_ERROR_CHAR_TO_X;
    }
    if(type_a == IKS_CHAR && type_b != IKS_CHAR || type_a == IKS_STRING && type_b != IKS_STRING){
       return IKS_ERROR_WRONG_TYPE;
    }
    return IKS_SUCESS;
}

int yystack_inf(int type_a, int type_b){
    
    if(type_a == type_b){
       return type_a;
    }
    if(type_a == IKS_FLOAT && type_b == IKS_INT || type_b == IKS_FLOAT && type_a == IKS_INT){
        return IKS_FLOAT;   
    }
    if(type_a == IKS_FLOAT && type_b == IKS_BOOL || type_b == IKS_FLOAT && type_a == IKS_BOOL){
        return IKS_FLOAT;   
    }
    if(type_a == IKS_INT && type_b == IKS_BOOL || type_b == IKS_INT && type_a == IKS_BOOL){
        return IKS_INT;   
    }
}

void yystack_push_scope(){
    
    printf("Push scope...\n");
    
    scopes = cc_stack_push(scopes);
}
void yystack_pop_scope(){
    
    printf("Pop scope...\n");
    scopes = cc_stack_pop(scopes);
}


int yytree_match_types_out(comp_tree_t* root){
 
    if(root!=NULL)
    {
        if(root->item->iks_type!=IKS_STRING && root->item->type!=AST_IDENTIFICADOR){
            return 1;
        }
        else {
            return yytree_match_types_out(root->children[1]);
        }
    }
    return 0;
}

int yystack_set_type(comp_tree_t* root){
 
    printf("\nROOT TYPE %d .", root->item->iks_type);


    scopes->top->type = root->item->iks_type;
}

int yystack_return_type(comp_tree_t* root){
    
    printf("\ntype fun %d .", scopes->top->type);
    printf("\ntype return %d .", root->item->iks_type);
    
    if(root->item->iks_type!=scopes->top->type){
        return 1;
    }else {
    
        return 0;
    }
}