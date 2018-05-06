%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yyerror(const char *message);
int can=1;
int na;
%}
%union{
    int ival;
    struct the{
        int front;
        int back;
        int number;
        int nope;
    }thes;
    char *cc;
}
%token <ival> INUMBER
%type <thes> expr
%token <cc> ca
%left '+'
%left '-'
%left '*'
%left '('
%left ')'
%left '['
%left ']'
%left ','
%left '^'
%left 'T'
%%
line    :expr ca    {
            if(can==1){
                printf("Accepted");
                return(0);
            }
            else{
                int j=$1.nope;
                int i;
                for(i=0;i<strlen($2);i++){
                    if($2[i]==' '){
                        na++;
                    }
                    else{
                        j--;
                        if(j==0){
                            break;
                        }
                    }
                }
                printf("Semantic error on col %d",$1.nope+na);
                return(0);
            }
        }
        ;
expr    :expr '+' expr  {
            $$.number=$1.number+1+$3.number;
            if($1.nope!=0){
                $$.nope=$1.nope;
            }
            else if($3.nope!=0){
                $$.nope=$3.nope+1+$1.number;
            }
            else{
                if($1.front==$3.front&&$1.back==$3.back){
                    $$.front=$1.front; $$.back=$3.back;
                }
                else{
                    can=0;
                    $$.nope=$1.number+1;
                }
            }
        }
        
        |expr '-' expr  {
            $$.number=$1.number+1+$3.number;
            if($1.nope!=0){
                $$.nope=$1.nope;
            }
            else if($3.nope!=0){
                $$.nope=$3.nope+1+$1.number;
            }
            else{
                if($1.front==$3.front&&$1.back==$3.back){
                    $$.front=$1.front; $$.back=$3.back;
                }
                else{
                    can=0;
                    $$.nope=$1.number+1;
                }
            }
        }
        
        |expr '*' expr  {
            $$.number=$1.number+1+$3.number;
            if($1.nope!=0){
                $$.nope=$1.nope;
            }
            else if($3.nope!=0){
                $$.nope=$3.nope+1+$1.number;
            }
            else{
                if($1.back==$3.front){
                    $$.front=$1.front; $$.back=$3.back;
                }
                else{
                    can=0;
                    $$.nope=$1.number+1;
                }
            }
        }
        
        |expr '^' 'T'  {
            $$.front=$1.back;
            $$.back=$1.front;
            $$.number=$1.number+2;
            if($1.nope!=0){
                $$.nope=$1.nope;
            }
        }
        |'(' expr ')'   {
            $$=$2;
            $$.number=$2.number+2;
            if($2.nope!=0){
                $$.nope=$2.nope+1;
            }
        }
        |'[' INUMBER ',' INUMBER ']'    {
            $$.number=3;
            $$.front=$2;
            $$.back=$4;
            while(($2/10)>0){
                $2=$2/10;
                $$.number++;
            }
            while(($4/10)>0){
                $4=$4/10;
                $$.number++;
            }
            $$.number+=2;
        }
        
        ;
%%
void yyerror(const char *message){
    fprintf(stderr,"%s\n",message);
}
int main(int argc,char *argv[]){
    yyparse();
    return(0);
}