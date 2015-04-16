#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_ast.h"
#include <stdlib.h>

comp_tree_t* ast;
comp_dict_t* stable;

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

void main_init (int argc, char **argv)
{
  //implemente esta função com rotinas de inicialização, se necessário
  stable = (comp_dict_t*)malloc(sizeof(comp_dict_t));
  cc_dict_init(stable);
}

void main_finalize (void)
{
  //implemente esta função com rotinas de inicialização, se necessário
  cc_dict_destroy(stable);
  //cc_tree_destroy_node(ast);
  free(stable);
}
