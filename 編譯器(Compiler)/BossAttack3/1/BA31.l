%option noyywrap
%{
#include"y.tab.h"
#include<string.h>
%}

ff          \\frac

%%
[\n]        {return(0);}
[0-9]+      {
                yylval.ival = atof(yytext);
                return(INUMBER);
            }
{ff}        {
                yylval.ca=yytext;
                return(expw);
            }
" "         {}
[\t]        {}
"+"|"{"|"}"|"-"|"^" {
                        return(yytext[0]);
                    }
.           {return(yytext[0]);}
%%
