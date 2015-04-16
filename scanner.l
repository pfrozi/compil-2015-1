/*
  Coloque aqui o identificador do grupo e dos seus membros
*/
white [ \t\n\r]
signal [-+]
digit [0-9]
letter [A-Za-z]
uinteger {digit}+
integer {uinteger}
floating {digit}*\.{digit}+
character [\040-\176]
ident _*{letter}*({letter}|{digit}|_)*
%{
#include "main.h"
#include "cc_misc.h"
#include <stdbool.h>
#include "parser.h" //arquivo automaticamente gerado pelo bison
struct comp_dict_item a;
int line_number=1;
%}
%x LCOMMENT
%x BCOMMENT
%%
"//"                {BEGIN(LCOMMENT);}
<LCOMMENT>"\n"      {line_number++;BEGIN(INITIAL);}
<LCOMMENT>.         {}
"/*"                {BEGIN(BCOMMENT);}
<BCOMMENT>"*/"      {BEGIN(INITIAL);}
<BCOMMENT>"\n"      line_number++;
<BCOMMENT>.         {}
[ \t\r]             {}
"int"               return (TK_PR_INT);
"float"             return (TK_PR_FLOAT);
"bool"              return (TK_PR_BOOL);
"char"              return (TK_PR_CHAR);
"string"            return (TK_PR_STRING);
"if"                return (TK_PR_IF);
"then"              return (TK_PR_THEN);
"else"              return (TK_PR_ELSE);
"while"             return (TK_PR_WHILE);
"do"                return (TK_PR_DO);
"input"             return (TK_PR_INPUT);
"output"            return (TK_PR_OUTPUT);
"return"            return (TK_PR_RETURN);
"const"             return (TK_PR_CONST);
"static"            return (TK_PR_STATIC);
"!"                 return (TK_OC_NEG);
"<="                return (TK_OC_LE);
">="                return (TK_OC_GE);
"=="                return (TK_OC_EQ);
"!="                return (TK_OC_NE);
"&&"                return (TK_OC_AND);
"||"                return (TK_OC_OR);
{integer}           {
                        comp_dict_item_key_t key=cc_dict_create_item_key(yytext,SIMBOLO_LITERAL_INT);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                        }
                        i->line=line_number;
                        i->type=SIMBOLO_LITERAL_INT;
                        i->val_int=atoi(yytext);
                        yylval.valor_simbolo_lexico = i;
                        return(TK_LIT_INT);
                    }
{floating}          {
                        comp_dict_item_key_t key = cc_dict_create_item_key(yytext,SIMBOLO_LITERAL_FLOAT);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                        }
                        i->line=line_number;
                        i->type=SIMBOLO_LITERAL_FLOAT;
                        i->val_float=atof(yytext);
                        yylval.valor_simbolo_lexico = i;
                        return(TK_LIT_FLOAT);
                    }
"true"              {
                        comp_dict_item_key_t key = cc_dict_create_item_key(yytext,SIMBOLO_LITERAL_BOOL);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                        }
                        i->line=line_number; 
                        i->type=SIMBOLO_LITERAL_BOOL;
                        i->val_bool=true;
                        yylval.valor_simbolo_lexico = i;
                        return(TK_LIT_TRUE);
                    }
"false"             {
                        comp_dict_item_key_t key = cc_dict_create_item_key(yytext,SIMBOLO_LITERAL_BOOL);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                        }
                        i->line=line_number;
                        i->type=SIMBOLO_LITERAL_BOOL;
                        i->val_bool=false;
                        yylval.valor_simbolo_lexico = i;
                        return(TK_LIT_FALSE);
                    }
\'[^\']\'           {
                        comp_dict_item_key_t key = cc_dict_create_item_key(yytext,SIMBOLO_LITERAL_CHAR);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                        }
                        i->line=line_number;
                        i->type=SIMBOLO_LITERAL_CHAR;
                        i->val_char=yytext[1];
                        yylval.valor_simbolo_lexico = i;
                        return(TK_LIT_CHAR);
                    }
\"[^\"]*\"          {
                        comp_dict_item_key_t key = cc_dict_create_item_key(yytext,SIMBOLO_LITERAL_STRING);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                            free(i->val_str);
                        }
                        char* dst = (char*)malloc(sizeof(char)*strlen(yytext));
                        strncpy(dst,yytext+1,strlen(yytext)-2);
                        i->line=line_number;
                        i->type=SIMBOLO_LITERAL_STRING;
                        i->val_str=dst;
                        yylval.valor_simbolo_lexico = i;
                        return(TK_LIT_STRING);
                    }
","                 return (TK_CE_COMMA);
";"                 return (TK_CE_SEMICOLON);
":"                 return (TK_CE_COLON);
"("                 return (TK_CE_PAR_OPEN);
")"                 return (TK_CE_PAR_CLOSE);
"["                 return (TK_CE_BRA_OPEN);
"]"                 return (TK_CE_BRA_CLOSE);
"+"                 return (TK_CE_PLUS);
"-"                 return (TK_CE_MINUS);
"*"                 return (TK_CE_MUL);
"/"                 return (TK_CE_DIV);
"<"                 return (TK_OC_LT);
">"                 return (TK_OC_GT);
"{"                 return (TK_CE_BRA_CURL_OPEN);
"}"                 return (TK_CE_BRA_CURL_CLOSE);
"="                 return (TK_CE_EQUAL);
"&"                 return (int)'&';
"$"                 return (int)'$';
"=>"                return (TK_CE_EG);
"\""                return (TOKEN_ERRO);
"\'"                return (TOKEN_ERRO);
"."                 return (TOKEN_ERRO);
{ident}             {
                        comp_dict_item_key_t key = cc_dict_create_item_key(yytext,SIMBOLO_IDENTIFICADOR);
                        comp_dict_item_t* i = cc_dict_get(stable,key);
                        if(i==NULL)
                        {
                            i=cc_dict_insert(stable,cc_dict_create_item(key,line_number));
                        }
                        else
                        {
                            free(key.lexem);
                            free(i->ident);
                        }
                        i->line=line_number;
                        i->type=SIMBOLO_IDENTIFICADOR;
                        i->ident=(char*)malloc(sizeof(char)*strlen(yytext)+1);
                        strncpy(i->ident,yytext,strlen(yytext));
                        yylval.valor_simbolo_lexico = i;
                        return(TK_IDENTIFICADOR);
                    }
"\n"                line_number++;
.                   return (TOKEN_ERRO);
<<EOF>>             return (TOKEN_EOF);
%%

