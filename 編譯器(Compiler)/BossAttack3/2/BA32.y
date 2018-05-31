%{
#include<stdio.h>
#include<stdlib.h>
int a[100000];
int bp,sp;
void yyerror(const char *message);
int i,j,k;
%}
%union{
    int ival;
    char *ca;
}
%token <ival> INUMBER
%token <ca> add
%token <ca> sub
%token <ca> mul
%token <ca> mod
%token <ca> load
%token <ca> inc
%token <ca> dec
%type <ival> expr

%%
line    :expr  {
            if(bp+1==sp){
                printf("%d\n",a[sp]);
            }
            else{
                printf("Invalid format\n");
            }
        }
        ;
expr    :expr expr{
        }
        |add            {
            if(sp-2<bp){
                printf("Invalid format\n");
                return(0);
            }
            i = a[sp--];
            j = a[sp--];
            a[++sp] = i+j;
        }
        |sub            {
            if(sp-2<bp){
                printf("Invalid format\n");
                return(0);
            }
            i = a[sp--];
            j = a[sp--];
            a[++sp] = i-j;
        }
        |mul            {
            if(sp-2<bp){
                printf("Invalid format\n");
                return(0);
            }
            i = a[sp--];
            j = a[sp--];
            a[++sp] = i*j;
        }
        |mod            {
            if(sp-2<bp){
                printf("Invalid format\n");
                return(0);
            }
            i = a[sp--];
            j = a[sp--];
            a[++sp] = i%j;
        }
        |load INUMBER   {
            a[++sp] = $2;
        }
        |inc            {
            if(sp==bp){
                printf("Invalid format\n");
                return(0);
            }
            a[sp]++;
        }
        |dec            {
            if(sp==bp){
                printf("Invalid format\n");
                return(0);
            }
            a[sp]--;
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