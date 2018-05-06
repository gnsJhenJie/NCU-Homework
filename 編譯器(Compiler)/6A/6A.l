%option noyywrap
%{
#include"y.tab.h"
#include<string.h>
int i;
char c[100];
%}

%%
[\n]        {yylval.cc=c; return(ca);}
[0-9]+      {
                strcat(c,yytext);
                yylval.ival = atoi(yytext);
                return(INUMBER);
            }
" "         {strcat(c,yytext);}
[\t]        {}
"+"|"("|")"|"-"|"*"|"["|"]"|","|"^"|"T" {strcat(c,yytext); return(yytext[0]);}
.           {strcat(c,yytext); return(yytext[0]);}
%%
