/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_PEDRO_DOCUMENTS_UFRGS_TRABCOMPILADORES_COMPIL_2015_1_BUILD_PARSER_H_INCLUDED
# define YY_YY_HOME_PEDRO_DOCUMENTS_UFRGS_TRABCOMPILADORES_COMPIL_2015_1_BUILD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_STATIC = 271,
    TK_PR_CONST = 272,
    TK_CE_COMMA = 273,
    TK_CE_SEMICOLON = 274,
    TK_CE_COLON = 275,
    TK_CE_PAR_OPEN = 276,
    TK_CE_PAR_CLOSE = 277,
    TK_CE_BRA_OPEN = 278,
    TK_CE_BRA_CLOSE = 279,
    TK_CE_BRA_CURL_OPEN = 280,
    TK_CE_BRA_CURL_CLOSE = 281,
    TK_CE_PLUS = 282,
    TK_CE_MINUS = 283,
    TK_CE_MUL = 284,
    TK_CE_DIV = 285,
    TK_CE_BRA_ANGL_OPEN = 286,
    TK_CE_BRA_ANGL_CLOSE = 287,
    TK_CE_EQUAL = 288,
    TK_CE_EXCL = 289,
    TK_CE_AMP = 290,
    TK_CE_EG = 291,
    TK_CE_DOLLAR = 292,
    TK_OC_LE = 293,
    TK_OC_GE = 294,
    TK_OC_EQ = 295,
    TK_OC_NE = 296,
    TK_OC_AND = 297,
    TK_OC_OR = 298,
    TK_OC_GT = 299,
    TK_OC_LT = 300,
    TK_OC_NEG = 301,
    TK_LIT_INT = 302,
    TK_LIT_FLOAT = 303,
    TK_LIT_FALSE = 304,
    TK_LIT_TRUE = 305,
    TK_LIT_CHAR = 306,
    TK_LIT_STRING = 307,
    TK_IDENTIFICADOR = 308,
    TOKEN_ERRO = 309,
    TOKEN_EOF = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:1909  */

    comp_dict_item_t *valor_simbolo_lexico;
    comp_tree_t      *ast;
    comp_list_t      *arguments;
    comp_list_t      *integer_list;
    int              integer;

#line 118 "/home/pedro/Documents/ufrgs/trabCompiladores/compil-2015-1/build/parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_PEDRO_DOCUMENTS_UFRGS_TRABCOMPILADORES_COMPIL_2015_1_BUILD_PARSER_H_INCLUDED  */
