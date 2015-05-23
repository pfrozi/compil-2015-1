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
#include "cc_list.h"
#include "main.h"
extern comp_tree_t* ast;
%}
/* Union for yylval */
%union {
    comp_dict_item_t *valor_simbolo_lexico;
    comp_tree_t      *ast;
    comp_list_t      *arguments;
    int              integer;
}

%type <ast> programa input line function func_head command_block single_command ret assignment 
%type <ast> in out flow_command command command2 val_exp cond op_literal func_call  
%type <ast> array dowhile whiledo lst_exp exp literal exp_art exp_art_t exp_art_par
%type <ast> exp_bool exp_bool_e exp_bool_ou exp_end exp_neg

%type <valor_simbolo_lexico> statement const_statement 
%type <arguments> func_params func_head_params

%type <integer> type lst_int array_int

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
        | statement array_int endline  { yystack_update_var($1, $2, IKS_ARRAY);         }
        | statement                    { yyerror("Missing a ;"); return SINTATICA_ERRO; }
        | statement array_int          { yyerror("Missing a ;"); return SINTATICA_ERRO; }
        
;
array:
          TK_CE_BRA_OPEN lst_exp TK_CE_BRA_CLOSE  {
                                                      if($2->item->iks_type==IKS_CHAR) return IKS_ERROR_CHAR_TO_X;
                                                      if($2->item->iks_type==IKS_STRING) return IKS_ERROR_STRING_TO_X; 
                                                      $$ = $2;
                                                  }
;
array_int:
          TK_CE_BRA_OPEN lst_int TK_CE_BRA_CLOSE  {
                                                      //if($2->item->iks_type==IKS_CHAR) return IKS_ERROR_CHAR_TO_X;
                                                      //if($2->item->iks_type==IKS_STRING) return IKS_ERROR_STRING_TO_X; 
                                                      $$ = $2;
                                                  }
;

statement:
          TK_PR_STATIC type TK_IDENTIFICADOR	    { 
                                                        if(yystack_find_top($3)!=NULL) 
                                                            return IKS_ERROR_DECLARED; 
                                                        else 
                                                            yystack_add($3, $2, IKS_VARIABLE); 
                                                        $$ = $3; 
                                                    }
        | type TK_IDENTIFICADOR			            { 
                                                        if(yystack_find_top($2)!=NULL) 
                                                            return IKS_ERROR_DECLARED; 
                                                        else 
                                                            yystack_add($2, $1, IKS_VARIABLE); 
                                                        $$ = $2; 
                                                    }
        | TK_PR_STATIC TK_IDENTIFICADOR             { yyerror("Missing a type"); return SINTATICA_ERRO; }
        | TK_IDENTIFICADOR                          { yyerror("Missing a type"); return SINTATICA_ERRO; }        
;

local_statement:
          const_statement TK_OC_LE TK_IDENTIFICADOR	{  }
        | const_statement TK_OC_LE literal
        | statement TK_OC_LE TK_IDENTIFICADOR		{  }
        | statement TK_OC_LE literal
        | const_statement 
        | statement 
        | const_statement TK_OC_LE                  { yyerror("Missing a attrib"); return SINTATICA_ERRO; }        
        | statement TK_OC_LE                        { yyerror("Missing a attrib"); return SINTATICA_ERRO; }        
;
const_statement:
          TK_PR_STATIC TK_PR_CONST type TK_IDENTIFICADOR	{ if(yystack_find_top($4)!=NULL) return IKS_ERROR_DECLARED; else yystack_add($4, $3, IKS_VARIABLE); $$ = $4; }
        | TK_PR_STATIC TK_PR_CONST TK_IDENTIFICADOR 		{ yyerror("Missing a type"); return SINTATICA_ERRO; }
        | TK_PR_STATIC TK_PR_CONST type             		{ yyerror("Missing a IDENTIFICADOR"); return SINTATICA_ERRO; }
        | TK_PR_CONST type TK_IDENTIFICADOR			        { if(yystack_find_top($3)!=NULL) return IKS_ERROR_DECLARED; else yystack_add($3,$2, IKS_VARIABLE); $$ = $3; }
        | TK_PR_CONST TK_IDENTIFICADOR              		{ yyerror("Missing a type"); return SINTATICA_ERRO; }
        | TK_PR_CONST type                          		{ yyerror("Missing a IDENTIFICADOR"); return SINTATICA_ERRO; }
;
literal:
          op_literal {$$ = $1;}
        | TK_LIT_STRING {$$ = cc_tree_create_node(1,cc_tree_item_create(AST_LITERAL,$1));}
;

op_literal:
          TK_LIT_INT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_INT,$1)),NULL);}
        | TK_LIT_FLOAT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_FLOAT,$1)),NULL);}
        | TK_LIT_FALSE {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_BOOL,$1)),NULL);}
        | TK_LIT_TRUE {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_BOOL,$1)),NULL);}
        | TK_LIT_CHAR {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_CHAR,$1)),NULL);}
        | TK_CE_PLUS TK_LIT_INT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_INT,$2)),NULL);}
        | TK_CE_PLUS TK_LIT_FLOAT {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_FLOAT,$2)),NULL);}
;

type:     TK_PR_INT    { $$ = IKS_INT; }
        | TK_PR_FLOAT  { $$ = IKS_FLOAT; }
        | TK_PR_BOOL   { $$ = IKS_BOOL; }
        | TK_PR_CHAR   { $$ = IKS_CHAR; }
        | TK_PR_STRING { $$ = IKS_STRING; }
;
exp:
          val_exp {$$ = $1;}
        | TK_LIT_STRING {$$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LITERAL,IKS_STRING,$1)),NULL);}
;

val_exp:
          exp_bool { $$ = $1; }
;
 /*
 
 $2
/  \
$1 $3

*/

exp_bool:
          exp_bool TK_OC_LT exp_bool_ou  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_L,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_bool TK_OC_GT exp_bool_ou  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_G,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_bool TK_OC_LE exp_bool_ou  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_LE,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_bool TK_OC_GE exp_bool_ou  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_GE,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_bool TK_OC_EQ exp_bool_ou  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_IGUAL,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_bool TK_OC_NE exp_bool_ou  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_COMP_DIF, yystack_inf($1->item, $3->item),NULL)), $1), $3); }
        | exp_bool_ou                    { $$ = $1; }
;
exp_bool_ou:
          exp_bool_ou TK_OC_OR exp_bool_e   { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_OU,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_bool_e                        { $$ = $1; }
;
exp_bool_e:
          exp_bool_e TK_OC_AND exp_art      { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_LOGICO_E,yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_art                           { $$ = $1; }
;
exp_art:
          exp_art TK_CE_PLUS exp_art_t  { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_ARIM_SOMA, yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_art TK_CE_MINUS exp_art_t { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_ARIM_SUBTRACAO, yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_art_t                     { $$ = $1; }
;
exp_art_t:
          exp_art_t TK_CE_MUL exp_art_par { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_ARIM_MULTIPLICACAO, yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_art_t TK_CE_DIV exp_art_par { if(yystack_verify_types($1->item->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->item->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_ARIM_DIVISAO, yystack_inf($1->item, $3->item), NULL)), $1), $3); }
        | exp_art_par                     { $$ = $1; }
;

exp_art_par:
          TK_CE_PAR_OPEN exp_bool TK_CE_PAR_CLOSE { $$ = $2; }
        | exp_neg                                 { $$ = $1; }
;


exp_neg:
          TK_CE_MINUS exp_end { $$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_ARIM_INVERSAO, $2->item->iks_type,NULL)),$2); }
        | TK_OC_NEG exp_end { $$ = cc_tree_insert_node(cc_tree_create_node(1,cc_tree_item_create_type(AST_LOGICO_COMP_NEGACAO, $2->item->iks_type,NULL)),$2); }
        | exp_end { $$ = $1;}
;


exp_end:
          func_call                              { $$ = $1; }
        | op_literal                             { $$ = $1; }
        | TK_IDENTIFICADOR                       { if(yystack_find($1)==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find($1)->iks_var!=IKS_VARIABLE) return yyerror_var($1); $$ = cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,$1->iks_type,$1)); }
        | TK_IDENTIFICADOR array                 { if(yystack_find($1)==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find($1)->iks_var!=IKS_ARRAY) return yyerror_var($1); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_VETOR_INDEXADO, $1->iks_type,NULL)),cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,$1->iks_type,$1))),$2);}
;

lst_exp:
          exp TK_CE_COMMA lst_exp { $$ = cc_tree_insert_node($1,$3);}
        | exp {$$ = $1;}
;

lst_int:
          TK_LIT_INT TK_CE_COMMA lst_int { $$ = $1->val_int * $3; }
        | TK_LIT_INT { $$ = $1->val_int; }
;

command_block:
         init_scope command close_scope { $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_BLOCO,NULL)),$2);}
;

init_scope:
        TK_CE_BRA_CURL_OPEN { yystack_push_scope(); }
;

close_scope:
        TK_CE_BRA_CURL_CLOSE { yystack_pop_scope(); }
;

command:
        /* %empty */ {$$ = NULL;}
        | command2 endline command {if($1!=NULL){$$ = cc_tree_insert_node($1,$3);} else{$$=$3;};}
        | command2 {if($1!=NULL){$$ = $1;}else{$$=NULL;}}
;
command2:
          single_command { $$ = $1;}
        | command_block { $$ = $1;}
        | flow_command { $$ = $1;}
        | endline {}
;
single_command:
          func_call              { $$ = $1;}
        | local_statement        { $$ = NULL;}
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
          func_head init_scope {yystack_set_type($1);} command close_scope { $$ = cc_tree_insert_node($1,$4);}
;
func_head:
          TK_PR_STATIC type TK_IDENTIFICADOR func_head_params  { if(yystack_find_top($3)!=NULL) return IKS_ERROR_DECLARED; else yystack_add($3, $2, IKS_FUNCTION); $$ = cc_tree_create_node(3,cc_tree_item_create_type(AST_FUNCAO,$2,$3)); $$->item->sentry->iks_arguments=$4;}
        | type TK_IDENTIFICADOR func_head_params               { if(yystack_find_top($2)!=NULL) return IKS_ERROR_DECLARED; else yystack_add($2, $1, IKS_FUNCTION); $$ = cc_tree_create_node(3,cc_tree_item_create_type(AST_FUNCAO,$1,$2)); $$->item->sentry->iks_arguments=$3;}
        | type func_head_params                                { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
        | TK_IDENTIFICADOR func_head_params                    { yyerror("Missing a type IDENTIFICADOR"); return SINTATICA_ERRO; }
;

func_head_params:
          TK_CE_PAR_OPEN TK_CE_PAR_CLOSE                       {$$ = NULL;}
        | TK_CE_PAR_OPEN func_params TK_CE_PAR_CLOSE           {$$ = $2;}
        | TK_CE_PAR_CLOSE                                      {yyerror("Missing ')'"); return SINTATICA_ERRO; }
        | TK_CE_PAR_OPEN                                       {yyerror("Missing '('"); return SINTATICA_ERRO; }
;
func_params:
          type TK_IDENTIFICADOR TK_CE_COMMA func_params               { $$ = cc_list_append(cc_list_create($1),$4);}
        | TK_PR_CONST type TK_IDENTIFICADOR TK_CE_COMMA func_params   { $$ = cc_list_append(cc_list_create($2),$5);}
        | type TK_IDENTIFICADOR                                       { $$ = cc_list_create($1);}
        | TK_PR_CONST type TK_IDENTIFICADOR                           { $$ = cc_list_create($2);}
        | TK_IDENTIFICADOR TK_CE_COMMA func_params              { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | TK_PR_CONST TK_IDENTIFICADOR TK_CE_COMMA func_params  { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | TK_IDENTIFICADOR                                      { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | TK_PR_CONST TK_IDENTIFICADOR                          { yyerror("Missing a param type"); return SINTATICA_ERRO; }
        | type                                                  { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
        | type TK_CE_COMMA func_params                          { yyerror("Missing a param IDENTIFICADOR"); return SINTATICA_ERRO; }
;

// atribuicao 
assignment:
          TK_IDENTIFICADOR TK_CE_EQUAL exp          { if(yystack_find($1)==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find($1)->iks_var!=IKS_VARIABLE) return yyerror_var($1); if(yystack_verify_types($1->iks_type,$3->item->iks_type)>0) return yystack_verify_types($1->iks_type,$3->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_ATRIBUICAO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1))),$3);}
        | TK_IDENTIFICADOR array TK_CE_EQUAL exp    { if(yystack_find($1)==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find($1)->iks_var!=IKS_ARRAY) return yyerror_var($1);if(yystack_verify_types($1->iks_type,$4->item->iks_type)>0) return yystack_verify_types($1->iks_type,$4->item->iks_type); $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_ATRIBUICAO,NULL)),cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_VETOR_INDEXADO,NULL)),cc_tree_create_node(1,cc_tree_item_create(AST_IDENTIFICADOR,$1))),$2)),$4);}
        | TK_IDENTIFICADOR TK_CE_EQUAL              { yyerror("Missing a expression"); return SINTATICA_ERRO; }        
        | TK_IDENTIFICADOR array TK_CE_EQUAL        { yyerror("Missing a expression"); return SINTATICA_ERRO; }        
;

// entrada
in:
          TK_PR_INPUT exp TK_CE_EG exp              { if($4->item->type!=AST_IDENTIFICADOR) return IKS_ERROR_WRONG_PAR_INPUT; $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create(AST_INPUT,NULL)),$2),$4);}
        | TK_PR_INPUT TK_CE_EG exp                  { yyerror("Missing a expression left of =>"); return SINTATICA_ERRO; } 
        | TK_PR_INPUT exp TK_CE_EG                  { yyerror("Missing a expression right of =>"); return SINTATICA_ERRO; } 
;
// saida
out:
          TK_PR_OUTPUT lst_exp                      { if(yytree_match_types_out($2)>0) return IKS_ERROR_WRONG_PAR_OUTPUT; $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_OUTPUT,NULL)),$2);}
        | TK_PR_OUTPUT                              { yyerror("Missing a expression list"); return SINTATICA_ERRO; } 
;

// retorno
ret:
          TK_PR_RETURN exp                          { if(yystack_return_type($2)>0) return IKS_ERROR_WRONG_PAR_RETURN; $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create(AST_RETURN,NULL)),$2);}
        | TK_PR_RETURN                              { yyerror("Missing a expression"); return SINTATICA_ERRO; } 
;

// Chamada da funcao 
func_call:
          TK_IDENTIFICADOR TK_CE_PAR_OPEN TK_CE_PAR_CLOSE { if(yystack_find($1)==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find($1)->iks_var!=IKS_FUNCTION) return yyerror_var($1); if($1->iks_arguments!=NULL) return IKS_ERROR_MISSING_ARGS; $$ = cc_tree_insert_node(cc_tree_create_node(2,cc_tree_item_create_type(AST_CHAMADA_DE_FUNCAO,yystack_find($1)->iks_type,NULL)),cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,yystack_find($1)->iks_type,$1))); }
        | TK_IDENTIFICADOR TK_CE_PAR_OPEN lst_exp TK_CE_PAR_CLOSE { if(yystack_find($1)==NULL) return IKS_ERROR_UNDECLARED; if(yystack_find($1)->iks_var!=IKS_FUNCTION) return yyerror_var($1); comp_list_t* args = yytree_get_argument_list($3); if(cc_list_length($1->iks_arguments)<cc_list_length(args)) return IKS_ERROR_EXCESS_ARGS; if(cc_list_length($1->iks_arguments)>cc_list_length(args)) return IKS_ERROR_MISSING_ARGS; if(yytree_match_arguments($1->iks_arguments,args)>0) return IKS_ERROR_WRONG_TYPE_ARGS; $$ = cc_tree_insert_node(cc_tree_insert_node(cc_tree_create_node(3,cc_tree_item_create_type(AST_CHAMADA_DE_FUNCAO,yystack_find($1)->iks_type,NULL)),$3),cc_tree_create_node(1,cc_tree_item_create_type(AST_IDENTIFICADOR,yystack_find($1)->iks_type,$1)));}
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
