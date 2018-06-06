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
If          if
DEFINE      define
ID          {letter}({letter}|{digit}|-)*
boolvaT     #t
boolvaF     #f
positive    [1-9]{digit}*
negitive    -{positive}
Number      0|{positive}|{negitive}


%%

{PrintNum}  {
                yylval.ca = yytext;
                return(print_num);
            }
{PrintBool} {
                yylval.ca = yytext;
                return(print_bool);
            }
{If}        {
                yylval.ca = yytext;
                return(iff);
            }
{DEFINE}    {
                yylval.ca = yytext;
                return(definee);
            }
{And}       {
                yylval.ca = yytext;
                return(and);
            }
{Or}        {
                yylval.ca = yytext;
                return(or);
            }
{Not}       {
                yylval.ca = yytext;
                return(not);
            }
{Mod}       {
                yylval.ca = yytext;
                return(mod);
            }
{Number}    {
                yylval.ival = atoi(yytext);
                return(number);
            }
{ID}        {
                yylval.ca = yytext;
                return(id);
            }
{boolvaT}    {
                yylval.ival = 1;
                return(boolval);
            }
{boolvaF}    {
                yylval.ival = 0;
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
