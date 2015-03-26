#include "cc_misc.h"
#include "cc_dict.h"
#include <stdlib.h>

//return the current line number
//incremented in scanner.l after
//every encontred newline
comp_dict_t* stable;

int getLineNumber (void)
{
  return line_number;
}

void yyerror (char const *mensagem)
{
  fprintf (stderr, "%s\n", mensagem); //altere para que apareça a linha
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
  free(stable);
}
