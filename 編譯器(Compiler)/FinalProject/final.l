%option noyywrap
%{
#include"y.tab.h"
#include<string.h>
%}

And         and
Or          or
Not         not
Mod         mod
letter      [a-z]
digit       [0-9]
PrintNum    print-num
PrintBool   print-bool
ID          {letter}({letter}|{digit}|-)*
boolva      #t|#f
positive    [1-9]{digit}*
negitive    -{positive}
Number      0|{positive}|{negitive}

%%

{PrintNum}  {
                yylval.ca=yytext;
                return(print_num);
            }
{PrintBool} {
                yylval.ca=yytext;
                return(print_bool);
            }
{And}       {
                yylval.ca=yytext;
                return(and);
            }
{Or}        {
                yylval.ca=yytext;
                return(or);
            }
{Not}       {
                yylval.ca=yytext;
                return(not);
            }
{Mod}       {
                yylval.ca=yytext;
                return(mod);
            }
{Number}    {
                yylval.ca=yytext;
                return(number);
            }
{ID}        {
                yylval.ca=yytext;
                return(id);
            }
{boolva}    {
                yylval.ca=yytext;
                return(boolval);
            }
" "         {}
[\t]        {}
[\r]        {}
[\n]        {}
"+"|"-"|"*"|"/"|">"|"<"|"="|"("|")"     {
                                            return(yytext[0]);
                                        }
.           {return(yytext[0]);}

%%
