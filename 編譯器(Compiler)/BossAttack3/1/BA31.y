%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void yyerror(const char *message);
int i,j,k;
%}
%union{
    float ival;
    char *ca;
}
%token <ival> INUMBER
%token <ca> expw
%type <ival> exps
%type <ival> expr
%left '+'
%left '{'
%left '}'
%left '-'
%left '^'
%%
line    :expr  {
            printf("%.3f",$1);
        }
        ;
expr    :exps           {
            $$ = $1;
        }
        |expr '+' exps  {
            $$ = $1+$3;
        }
        |expr '-' exps  {
            $$ = $1-$3;
        }
        ;
exps    :INUMBER        {
            $$=$1;
        }
        |'{' expr '}'   {
            $$ = $2;
        }
        |expw '{' expr '}' '{' expr '}' {
            $$ = $3/$6;
        }
        |exps '^' exps  {
            $$ = pow($1,$3);
        }
        ;
%%
void yyerror(const char *message){
    printf("Invalid format\n");
}
int main(int argc,char *argv[]){
    yyparse();
    return(0);
}