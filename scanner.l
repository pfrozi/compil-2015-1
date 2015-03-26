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
#include "parser.h" //arquivo automaticamente gerado pelo bison
#include "cc_misc.h"
#include "cc_dict.h"
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
"<="                return (TK_OC_LE);
">="                return (TK_OC_GE);
"=="                return (TK_OC_EQ);
"!="                return (TK_OC_NE);
"&&"                return (TK_OC_AND);
"||"                return (TK_OC_OR);
{integer}           {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_LIT_INT);
                    }
{floating}          {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_LIT_FLOAT);
                    }
"true"              {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_LIT_TRUE);
                    }
"false"             {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_LIT_FALSE);
                    }
\'[^\']\'           {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_LIT_CHAR);
                    }
\"[^\"]*\"          {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_LIT_STRING);
                    }
","                 return (int)',';
";"                 return (int)';';
":"                 return (int)':';
"("                 return (int)'(';
")"                 return (int)')';
"["                 return (int)'[';
"]"                 return (int)']';
"+"                 return (int)'+';
"-"                 return (int)'-';
"*"                 return (int)'*';
"/"                 return (int)'/';
"<"                 return (int)'<';
">"                 return (int)'>';
"{"                 return (int)'{';
"}"                 return (int)'}';
"="                 return (int)'=';
"!"                 return (int)'!';
"&"                 return (int)'&';
"$"                 return (int)'$';
"\""                return (TOKEN_ERRO);
"\'"                return (TOKEN_ERRO);
"."                 return (TOKEN_ERRO);
{ident}             {
                        comp_dict_item_t* i = cc_dict_get(stable,yytext);
                        if(i==NULL)
                        {
                            cc_dict_insert(stable,cc_dict_create_item(yytext,line_number));
                        }
                        else
                        {
                            i->line=line_number;
                        } 
                        return(TK_IDENTIFICADOR);
                    }
"\n"                line_number++;
%%

