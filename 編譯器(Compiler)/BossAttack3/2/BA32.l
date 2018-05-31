%option noyywrap
%{
#include"y.tab.h"
#include<string.h>
%}

a           add
b           sub
c           mul
d           mod
e           load
f           inc
g           dec

%%
[0-9]+      {
                yylval.ival = atoi(yytext);
                return(INUMBER);
            }
{a}         {
                yylval.ca=yytext;
                return(add);
            }
{b}         {
                yylval.ca=yytext;
                return(sub);
            }
{c}         {
                yylval.ca=yytext;
                return(mul);
            }
{d}         {
                yylval.ca=yytext;
                return(mod);
            }
{e}         {
                yylval.ca=yytext;
                return(load);
            }
{f}         {
                yylval.ca=yytext;
                return(inc);
            }
{g}         {
                yylval.ca=yytext;
                return(dec);
            }
" "         {}
[\t]        {}
[\n]        {}
.           {return(yytext[0]);}
%%
