%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yyerror(const char *message);


%}
%union{
    char *ca;
    char cc[10000];
}
%token <ca> and
%token <ca> or
%token <ca> not
%token <ca> mod
%token <ca> number
%token <ca> id
%token <ca> boolval
%token <ca> print_num
%token <ca> print_bool
%type <cc> PROGRAM
%type <cc> STMT
%type <cc> PRINT_STMT
%type <cc> EXP
%type <cc> NUM_OP
%type <cc> PLUS
%type <cc> MINUS
%type <cc> MULTIPLY
%type <cc> DIVIDE
%type <cc> MODULUS
%type <cc> GREATER
%type <cc> SMALLER
%type <cc> EQUAL
%type <cc> LOGICAL_OP
%type <cc> AND_OP
%type <cc> OR_OP
%type <cc> NOT_OP
 
%left '+'
%left '-'
%left '*'
%left '/'
%left '('
%left ')'
%left '<'
%left '>'
%left '='

%%

PROGRAM     :PROGRAM STMT           {
                printf("successfulllllllllll\n");
            }
            |STMT                   {
                printf("successful\n");
            }
            ;
STMT        :EXP                    {

            }
            |PRINT_STMT             {

            }
            ;
PRINT_STMT  :'(' print_num EXP ')'  {

            }
            |'(' print_bool EXP ')' {

            }
            ;
EXP         :boolval                {

            }
            |number                 {

            }
            |NUM_OP                 {

            }
            |LOGICAL_OP             {

            }
            |EXP EXP                {
                
            }
            ;
NUM_OP      :PLUS                   {

            }
            |MINUS                  {

            }
            |MULTIPLY               {

            }
            |DIVIDE                 {

            }
            |MODULUS                {

            }
            |GREATER                {

            }
            |SMALLER                {

            }
            |EQUAL                  {

            }
            ;
PLUS        :'(' '+' EXP EXP ')'    {

            }
            ;
MINUS       :'(' '-' EXP EXP ')'    {

            }
            ;
MULTIPLY    :'(' '*' EXP EXP ')'    {

            }
            ;
DIVIDE      :'(' '/' EXP EXP ')'    {

            }
            ;
MODULUS     :'(' mod EXP EXP ')'    {

            }
            ;
GREATER     :'(' '>' EXP EXP ')'    {

            }
            ;
SMALLER     :'(' '<' EXP EXP ')'    {

            }
            ;
EQUAL       :'(' '=' EXP EXP ')'    {

            }
            ;
LOGICAL_OP  :AND_OP                 {

            }
            |OR_OP                  {

            }
            |NOT_OP                 {

            }
            ;
AND_OP      :'(' and EXP EXP ')'    {

            }
            ;
OR_OP       :'(' or EXP EXP ')'     {

            }
            ;
NOT_OP      :'(' not EXP ')'    {

            }
            ;

%%

void yyerror(const char *message){
    printf("syntax error\n");
}
int main(int argc,char *argv[]){
    yyparse();
    return(0);
}