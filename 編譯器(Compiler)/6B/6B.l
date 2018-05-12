%option noyywrap
%{
#include"y.tab.h"
#include<string.h>
int nope=1;
%}

ch          [A-Z]{1}[a-z]*

%%
[\n]        {return(0);}
[0-9]+      {
                if(nope==0){
                    return(0);
                }
                yylval.ival = atoi(yytext);
                return(INUMBER);
            }
{ch}        {
                nope=1;
                yylval.ca=yytext;
                return(expw);
            }
" "         {}
[\t]        {}
"+"|"("|")"|"-"|">" {
                        if(yytext[0]=='('){
                            nope=0;
                        }
                        else{
                            nope=1;
                        }
                        return(yytext[0]);
                    }
.           {return(yytext[0]);}
%%
