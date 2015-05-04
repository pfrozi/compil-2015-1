/*
  main.h

  Cabeçalho principal do analisador sintático
*/
#ifndef __MAIN_H
#define __MAIN_H
#include <stdio.h>
#include "cc_dict.h"
#include "cc_list.h"
#include "cc_tree.h"
#include "parser.h"

/*
  Constantes a serem utilizadas como valor de retorno no caso de
  sucesso (SINTATICA_SUCESSO) e erro (SINTATICA_ERRO) do analisador
  sintático.
*/
#define SINTATICA_SUCESSO 0
#define SINTATICA_ERRO    1

/*
  Constantes a serem utilizadas para diferenciar os lexemas que estão
  registrados na tabela de símbolos.
*/
#define SIMBOLO_LITERAL_INT    1
#define SIMBOLO_LITERAL_FLOAT  2
#define SIMBOLO_LITERAL_CHAR   3
#define SIMBOLO_LITERAL_STRING 4
#define SIMBOLO_LITERAL_BOOL   5
#define SIMBOLO_IDENTIFICADOR  6


/* Codigos de tipos da linguagem amarela */
#define IKS_INT             1
#define IKS_FLOAT           2
#define IKS_CHAR            3
#define IKS_STRING          4
#define IKS_BOOL            5

/*
  Constantes a serem utilizadas como valor de retorno do analisador
  semantico.
*/
#define IKS_SUCESS                        0   // Nenhum erro semantico

/* Verificacao das declaracoes */
#define IKS_ERROR_UNDECLARED              1   // Identificador nao declarado
#define IKS_ERROR_DECLARED                2   // Identificador jah declarado

/* Uso correto dos identificadores */ 
#define IKS_ERROR_VARIABLE                3   // Identificador deve ser usado como variavel
#define IKS_ERROR_VECTOR                  4   // Identificador deve ser utilizado como vetor
#define IKS_ERROR_FUNCTION                5   // Identificador deve ser usado como funcao

/* Tipos e tamanho de dados */
#define IKS_ERROR_WRONG_TYPE              6   // Tipos incompatives
#define IKS_ERROR_STRING_TO_X             7   // coercao impossivel do tipo string
#define IKS_ERROR_CHAR_TO_X               8   // coercao impossivel do tipo char 

/* Argumentos e parametros */
#define IKS_ERROR_MISSING_ARGS            9   // Faltam argumentos
#define IKS_ERROR_EXCESS_ARGS             10  // Sobram argumentos
#define IKS_ERROR_WRONG_TYPE_ARGS         11  // Argumentos incompativeis 

/* Verificacao de tipos em comandos */
#define IKS_ERROR_WRONG_PAR_INPUT         12  // Param nao eh identificador
#define IKS_ERROR_WRONG_PAR_OUTPUT        13  // Param nao eh literal string ou expressao 
#define IKS_ERROR_WRONG_PAR_RETURN        14  // Param nao eh expressao compativel com o tipo de retorno


#endif
