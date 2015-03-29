/*
    Wladimir's group
        Lucas Herbert Jones
        Pedro Henrique Frozi
        Wladimir Leuschner
*/
%{
#include <stdio.h>
#include "main.h"
%}

/* Declaração dos tokens da linguagem */
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_STATIC
%token TK_PR_CONST
%token TK_CE_COMMA
%token TK_CE_SEMICOLON
%token TK_CE_COLON
%token TK_CE_PAR_OPEN
%token TK_CE_PAR_CLOSE
%token TK_CE_BRA_OPEN
%token TK_CE_BRA_CLOSE
%token TK_CE_BRA_CURL_OPEN
%token TK_CE_BRA_CURL_CLOSE
%token TK_CE_PLUS
%token TK_CE_MINUS
%token TK_CE_MUL
%token TK_CE_DIV
%token TK_CE_BRA_ANGL_OPEN
%token TK_CE_BRA_ANGL_CLOSE
%token TK_CE_EQUAL
%token TK_CE_EXCL
%token TK_CE_AMP
%token TK_CE_DOLLAR
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO

%%
// VERIFICAR COMANDO VAZIO!
/* Regras (e ações) da gramática */
programa:
        input { return SINTATICA_SUCESSO; }
;

input:    empty 
        | line 
        | line input 
;
empty:
          ""
        | " "
        | '\n'
;
line:      
          global_statement
        | function
;  
endline:
          TK_CE_SEMICOLON
;

global_statement:
          statement endline        // int x; int static x;
        | statement array endline  // int x[6]; int static x[7];
;
array:
          TK_CE_BRA_OPEN TK_LIT_INT TK_CE_BRA_CLOSE   // x[1]
;
statement:
          TK_PR_STATIC type TK_IDENTIFICADOR
        | type TK_IDENTIFICADOR
;

local_statement:
          TK_IDENTIFICADOR TK_OC_LE const_statement endline
        | literal TK_OC_LE statement endline
        | const_statement endline
        | statement endline
;
const_statement:
          TK_PR_STATIC TK_PR_CONST type TK_IDENTIFICADOR
        | TK_PR_CONST type TK_IDENTIFICADOR
;
literal:
          TK_LIT_INT
        | TK_LIT_FLOAT
        | TK_LIT_FALSE
        | TK_LIT_TRUE
        | TK_LIT_CHAR
        | TK_LIT_STRING
;
type:     TK_PR_INT
        | TK_PR_FLOAT
        | TK_PR_BOOL
        | TK_PR_CHAR
        | TK_PR_STRING
;

exp:
          
          
;
lst_exp:
          exp TK_CE_COMMA lst_exp
        | exp
;

command_block:
          TK_CE_BRA_CURL_OPEN command TK_CE_BRA_CURL_CLOSE
;
command:
          local_statement
        | exp
        | %empty
;
function:
          func_head command_block
;
func_head:
          TK_PR_STATIC type TK_IDENTIFICADOR func_head_params
        | type TK_IDENTIFICADOR func_head_params
;

func_head_params:
          TK_CE_PAR_OPEN TK_CE_PAR_CLOSE
        | TK_CE_PAR_OPEN func_params TK_CE_PAR_CLOSE
;
func_params:
          type TK_IDENTIFICADOR TK_CE_COMMA func_params
        | TK_PR_CONST type TK_IDENTIFICADOR TK_CE_COMMA func_params
        | type TK_IDENTIFICADOR
        | TK_PR_CONST type TK_IDENTIFICADOR 
        
;

// atribuicao 
assignment:
          TK_IDENTIFICADOR TK_CE_EQUAL literal
        | TK_IDENTIFICADOR array TK_CE_EQUAL literal
;

// entrada
in:
          TK_PR_INPUT exp TK_CE_EG exp 
;
// saida
out:
          TK_PR_OUTPUT lst_exp
;

// retorno
ret:
          TK_PR_RETURN exp
;

// Chamada da funcao 
func_call:
          TK_IDENTIFICADOR TK_CE_PAR_OPEN TK_CE_PAR_CLOSE
        | TK_IDENTIFICADOR TK_CE_PAR_OPEN lst_exp TK_CE_PAR_CLOSE
;

/* End of grammar */
%%
