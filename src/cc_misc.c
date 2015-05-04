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
}

comp_dict_item_t* yystack_find(comp_dict_item_t* sentry){
    
    comp_dict_item_t* item = cc_stack_find_top(scopes, sentry);
    return item;
}
void yystack_add(comp_dict_item_t* sentry, int iks_type, int iks_var){
    
    sentry->iks_type = iks_type;
    sentry->iks_var = iks_var;
    
    scopes = cc_stack_add_top(scopes, sentry);
}
void yystack_update_var(comp_dict_item_t* sentry, int var){
    
    yystack_find(sentry)->iks_var = var;
    cc_dict_get(stable, sentry->key)->iks_var = var;
    
}
