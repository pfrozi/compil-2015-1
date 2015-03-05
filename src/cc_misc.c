#include "cc_misc.h"
#include "cc_dict.h"


int getLineNumber (void)
{
  //implemente esta função
  //return -1;
  return line_number;
}

void yyerror (char const *mensagem)
{
  fprintf (stderr, "%s\n", mensagem); //altere para que apareça a linha
}

void main_init (int argc, char **argv)
{
  //implemente esta função com rotinas de inicialização, se necessário
  cc_dict_init();
}

void main_finalize (void)
{
  //implemente esta função com rotinas de inicialização, se necessário
  cc_dict_destroy();
}
