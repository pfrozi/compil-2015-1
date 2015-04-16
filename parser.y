/*
    Wladimir's group
        Lucas Herbert Jones
        Pedro Henrique Frozi
        Wladimir Leuschner
*/
%{
#include <stdio.h>
#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_tree.h"
#include "cc_ast.h"
#include "main.h"
extern comp_tree_t* ast;
%}
/* Union for yylval */
%union {
    comp_dict_item_t *valor_simbolo_lexico;
    comp_tree_t *ast;
}

%type <ast> programa input line function func_head command_block single_command in out ret assignment flow_command command command2 exp exp1 val_exp arith_op log_op end_exp cond op_literal func_call array dowhile whiledo lst_exp literal
%error-verbose

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
%token TK_CE_EG
%token TK_CE_DOLLAR
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_GT
%token TK_OC_LT
%token TK_OC_NEG
%token <valor_simbolo_lexico> TK_LIT_INT
%token <valor_simbolo_lexico> TK_LIT_FLOAT
%token <valor_simbolo_lexico> TK_LIT_FALSE
%token <valor_simbolo_lexico> TK_LIT_TRUE
%token <valor_simbolo_lexico> TK_LIT_CHAR
%token <valor_simbolo_lexico> TK_LIT_STRING
%token <valor_simbolo_lexico> TK_IDENTIFICADOR
%token TOKEN_ERRO
%token TOKEN_EOF
%right TK_PR_THEN TK_PR_ELSE
%%
// VERIFICAR COMANDO VAZIO!
/* Regras (e ações) da gramática */
programa:
          input TOKEN_EOF {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_PROGRAMA,NULL)),$1); ast=$$ ;return SINTATICA_SUCESSO; }
;

input:    /*empty*/ {$$ = NULL;}
        | line input {$$ = cc_tree_insert_node($1,$2);}
        | global_line input {$$ = $2;}
;

global_line:
          global_statement {}
;

line:
          function {$$ = $1;}
;  
endline:
          TK_CE_SEMICOLON
;

global_statement:
          statement endline        // int x; int static x;
        | statement array endline  // int x[6]; int static x[7];
        | statement                { yyerror("Missing a ;"); return SINTATICA_ERRO; }
        | statement array          { yyerror("Missing a ;"); return SINTATICA_ERRO; }
        
;
array:
          TK_CE_BRA_OPEN exp TK_CE_BRA_CLOSE   {$$ = $2;};
;

statement:
          TK_PR_STATIC type TK_IDENTIFICADOR
        | type TK_IDENTIFICADOR
        | TK_PR_STATIC TK_IDENTIFICADOR             { yyerror("Missing a type"); return SINTATICA_ERRO; }
        | TK_IDENTIFICADOR                          { yyerror("Missing a type"); return SINTATICA_ERRO; }        
;

local_statement:
          const_statement TK_OC_LE TK_IDENTIFICADOR
        | const_statement TK_OC_LE literal
        | statement TK_OC_LE TK_IDENTIFICADOR
        | statement TK_OC_LE literal
        | const_statement 
        | statement 
        | const_statement TK_OC_LE                  { yyerror("Missing a attrib"); return SINTATICA_ERRO; }        
        | statement TK_OC_LE                        { yyerror("Missing a attrib"); return SINTATICA_ERRO; }        
;
const_statement:
          TK_PR_STATIC TK_PR_CONST type TK_IDENTIFICADOR
        | TK_PR_STATIC TK_PR_CONST TK_IDENTIFICADOR { yyerror("Missing a type"); return SINTATICA_ERRO; }
        | TK_PR_STATIC TK_PR_CONST type             { yyerror("Missing a IDENTIFICADOR"); return SINTATICA_ERRO; }
        | TK_PR_CONST type TK_IDENTIFICADOR
        | TK_PR_CONST TK_IDENTIFICADOR              { yyerror("Missing a type"); return SINTATICA_ERRO; }
        | TK_PR_CONST type                          { yyerror("Missing a IDENTIFICADOR"); return SINTATICA_ERRO; }
;
literal:
          op_literal {$$ = $1;}
        | TK_LIT_STRING {$$ = cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1));}
;
op_literal:
          TK_LIT_INT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1)),NULL);}
        | TK_LIT_FLOAT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1)),NULL);}
        | TK_OC_NEG TK_LIT_FALSE {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LOGICO_COMP_NEGACAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
        | TK_LIT_FALSE {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1)),NULL);}
        | TK_OC_NEG TK_LIT_TRUE {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LOGICO_COMP_NEGACAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
        | TK_LIT_TRUE {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1)),NULL);}
        | TK_LIT_CHAR {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1)),NULL);}
        | TK_CE_MINUS TK_LIT_INT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
        | TK_CE_MINUS TK_LIT_FLOAT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
        | TK_CE_PLUS TK_LIT_INT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
        | TK_CE_PLUS TK_LIT_FLOAT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
;
type:     TK_PR_INT
        | TK_PR_FLOAT
        | TK_PR_BOOL
        | TK_PR_CHAR
        | TK_PR_STRING
;
exp:
          val_exp {$$ = $1;}
        | TK_LIT_STRING {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1)),NULL);}
;

val_exp:
          exp1 {$$ = $1;}
        | val_exp arith_op exp1 {$$ = cc_tree_insert_node(cc_tree_insert_node($2,$1),$3);}
        | val_exp log_op exp1 {$$ = cc_tree_insert_node(cc_tree_insert_node($2,$1),$3);}
;
exp1:
          TK_CE_PAR_OPEN val_exp TK_CE_PAR_CLOSE {$$ = $2;}
        | end_exp {$$ = $1;}
;
end_exp:
          func_call {$$ = $1;}
        | TK_CE_MINUS func_call {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),$2);}
        | TK_OC_NEG func_call {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LOGICO_COMP_NEGACAO,NULL)),$2);}
        | op_literal {$$ = $1;}
        | TK_IDENTIFICADOR {$$ = cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1));}
        | TK_CE_MINUS TK_IDENTIFICADOR {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}
        | TK_OC_NEG TK_IDENTIFICADOR {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_LOGICO_COMP_NEGACAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$2)));}

        | TK_IDENTIFICADOR array {$$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_VETOR_INDEXADO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1))),$2);}

        | TK_OC_NEG TK_IDENTIFICADOR array {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create(AST_ARIM_INVERSAO,NULL)),cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_VETOR_INDEXADO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$2))),$3));}
;

/*
arith_exp:
          arith_op exp
;
*/
arith_op:
          TK_CE_PLUS {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_ARIM_SOMA,NULL));}
        | TK_CE_MINUS {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_ARIM_SUBTRACAO,NULL));}
        | TK_CE_MUL {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_ARIM_MULTIPLICACAO,NULL));}
        | TK_CE_DIV {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_ARIM_DIVISAO,NULL));}
;
/*
log_exp:
          exp log_op
;
*/
log_op:
          TK_OC_LT {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_COMP_L,NULL));}
        | TK_OC_GT {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_COMP_G,NULL));}
        | TK_OC_LE {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_COMP_LE,NULL));}
        | TK_OC_GE {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_COMP_GE,NULL));}
        | TK_OC_EQ {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_COMP_IGUAL,NULL));}
        | TK_OC_NE {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_COMP_DIF,NULL));}
        | TK_OC_AND {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_E,NULL));}
        | TK_OC_OR {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_LOGICO_OU,NULL));}
;
lst_exp:
          exp TK_CE_COMMA lst_exp { $$ = cc_tree_insert_node($1,$3);}
        | exp {$$ = $1;}
;

command_block:
         TK_CE_BRA_CURL_OPEN command TK_CE_BRA_CURL_CLOSE { $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_BLOCO,NULL)),$2);}
;

command:
        /* %empty */ {$$ = NULL;}
        | command2 endline command {$$ = cc_tree_insert_node($1,$3);}
        | command2 {$$ = $1;}
;
command2:
          single_command { $$ = $1;}
        | command_block { $$ = $1;}
        | flow_command { $$ = $1;}
        | endline {}
;
single_command:
          func_call              { $$ = $1;}
        | local_statement        {}
        | in                     { $$ = $1;}
        | out                    { $$ = $1;} 
        | ret                    { $$ = $1;}
        | assignment             { $$ = $1;}
;
flow_command:
          cond                   { $$ = $1;}
        | whiledo                { $$ = $1;}
        | dowhile                { $$ = $1;}
;
function:
          func_head TK_CE_BRA_CURL_OPEN command TK_CE_BRA_CURL_CLOSE {$$ = cc_tree_insert_node($1,$3);}
;
func_head:
          TK_PR_STATIC type TK_IDENTIFICADOR func_head_params  {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_FUNCAO,$3));}
        | type TK_IDENTIFICADOR func_head_params               {$$ = cc_tree_create_node(3,cc_tree_item_create(AST_FUNCAO,$2));}
        | type func_head_params                                { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
        | TK_IDENTIFICADOR func_head_params                    { yyerror("Missing a type IDENTIFICADOR"); return SINTATICA_ERRO; }
;

func_head_params:
          TK_CE_PAR_OPEN TK_CE_PAR_CLOSE
        | TK_CE_PAR_OPEN func_params TK_CE_PAR_CLOSE
        | TK_CE_PAR_CLOSE                                      {yyerror("Missing ')'"); return SINTATICA_ERRO; }
        | TK_CE_PAR_OPEN                                       {yyerror("Missing '('"); return SINTATICA_ERRO; }
;
func_params:
          type TK_IDENTIFICADOR TK_CE_COMMA func_params
        | TK_PR_CONST type TK_IDENTIFICADOR TK_CE_COMMA func_params
        | type TK_IDENTIFICADOR
        | TK_PR_CONST type TK_IDENTIFICADOR 
        | TK_IDENTIFICADOR TK_CE_COMMA func_params              { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | TK_PR_CONST TK_IDENTIFICADOR TK_CE_COMMA func_params  { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | TK_IDENTIFICADOR                                      { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | TK_PR_CONST TK_IDENTIFICADOR                          { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | type                                                  { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
        | type TK_CE_COMMA func_params                          { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
;

// atribuicao 
assignment:
          TK_IDENTIFICADOR TK_CE_EQUAL exp          { $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_ATRIBUICAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1))),$3);}
        | TK_IDENTIFICADOR array TK_CE_EQUAL exp    {$$ = cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_ATRIBUICAO,NULL)),cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_VETOR_INDEXADO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1))),$2));}
        | TK_IDENTIFICADOR TK_CE_EQUAL              { yyerror("Missing a expression"); return SINTATICA_ERRO; }        
        | TK_IDENTIFICADOR array TK_CE_EQUAL        { yyerror("Missing a expression"); return SINTATICA_ERRO; }        
;

// entrada
in:
          TK_PR_INPUT exp TK_CE_EG exp              { $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_INPUT,NULL)),$2),$4);}
        | TK_PR_INPUT TK_CE_EG exp                  { yyerror("Missing a expression left of =>"); return SINTATICA_ERRO; } 
        | TK_PR_INPUT exp TK_CE_EG                  { yyerror("Missing a expression right of =>"); return SINTATICA_ERRO; } 
;
// saida
out:
          TK_PR_OUTPUT lst_exp                      { $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_OUTPUT,NULL)),$2);}
        | TK_PR_OUTPUT                              { yyerror("Missing a expression list"); return SINTATICA_ERRO; } 
;

// retorno
ret:
          TK_PR_RETURN exp                          { $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_RETURN,NULL)),$2);}
        | TK_PR_RETURN                              { yyerror("Missing a expression"); return SINTATICA_ERRO; } 
;

// Chamada da funcao 
func_call:
          TK_IDENTIFICADOR TK_CE_PAR_OPEN TK_CE_PAR_CLOSE { $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_CHAMADA_DE_FUNCAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1)));}
        | TK_IDENTIFICADOR TK_CE_PAR_OPEN lst_exp TK_CE_PAR_CLOSE { $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_CHAMADA_DE_FUNCAO,NULL)),$3),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1)));}
;
// if

cond:
          TK_PR_IF TK_CE_PAR_OPEN exp TK_CE_PAR_CLOSE TK_PR_THEN command2 {$$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(4,cc_tree_item_create(AST_IF_ELSE,NULL)),$3),$6);}

        | TK_PR_IF TK_CE_PAR_OPEN exp TK_CE_PAR_CLOSE TK_PR_THEN command2 TK_PR_ELSE command2 {$$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(4,cc_tree_item_create(AST_IF_ELSE,NULL)),$3),$6),$8);}
        | TK_PR_IF TK_CE_PAR_OPEN TK_CE_PAR_CLOSE TK_PR_THEN command2           { yyerror("if statement without expression"); return SINTATICA_ERRO; }
        | TK_PR_IF TK_CE_PAR_OPEN exp TK_PR_THEN command2                       { yyerror("Missing ')'"); return SINTATICA_ERRO; }
;
whiledo:
          TK_PR_WHILE TK_CE_PAR_OPEN exp TK_CE_PAR_CLOSE TK_PR_DO command2      { $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_WHILE_DO,NULL)),$3),$6);}
        | TK_PR_WHILE TK_CE_PAR_OPEN TK_CE_PAR_CLOSE TK_PR_DO command2          { yyerror("while statement without expression"); return SINTATICA_ERRO; }        
;

dowhile:
          TK_PR_DO command2 TK_PR_WHILE exp                                     { $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_DO_WHILE,NULL)),$2),$4);}
        | TK_PR_DO command2 TK_PR_WHILE                                         { yyerror("do statement without expression"); return SINTATICA_ERRO; }
;
/* End of grammar */
%%
