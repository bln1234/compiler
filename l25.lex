%option nounput
%{
#include <cstdio>
#include <vector>
#include "l25.tab.hpp"
%}

%%

"program"       { return PROGRAM; }
"func"          { return FUNC; }
"main"          { return MAIN; }
"return"        { return RETURN; }
"let"           { return LET; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"input"         { return INPUT; }
"output"        { return OUTPUT; }
"struct_def"    { return STRUCT_DEF; }
"struct"        { return STRUCT; }

"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LT; }
">"             { return GT; }

"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
","             { return COMMA; }
";"             { return SEMICOLON; }
"."             {return DOT; }

[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return IDENT; }

[ \t\n]+        { /* 忽略空白 */ }
.               { printf("Unrecognized character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}    