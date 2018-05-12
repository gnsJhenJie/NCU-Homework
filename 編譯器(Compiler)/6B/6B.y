%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yyerror(const char *message);
int i,j,k;
int n=0;
int finded;
struct the{
    char s[10];
    int number;
}thes[100];
struct the tempthe;

%}
%union{
    int ival;
    char *ca;
    char cc[10000];
}
%token <ival> INUMBER
%token <ca> expw
%type <cc> expf
%type <cc> exps
%type <cc> expr
%left '+'
%left '('
%left ')'
%left '-'
%left '>'
%%
line    :expr '-' '>' expr  {
            
            for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                    if(thes[j].s[0] > thes[j+1].s[0]){
                        tempthe=thes[j];
                        thes[j]=thes[j+1];
                        thes[j+1]=tempthe;
                    }
                    else if(thes[j].s[0] == thes[j+1].s[0]){
                        if(thes[j].s[1] > thes[j+1].s[1]){
                            tempthe=thes[j];
                            thes[j]=thes[j+1];
                            thes[j+1]=tempthe;
                        }
                    }
                }
            }
            
            for(i=0;i<strlen($1);i++){
                if('A'<=$1[i] && $1[i]<='Z'){
                    for(j=i+1;j<strlen($1);j++){
                        if('a'<=$1[j] && $1[j]<='z'){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    
                    for(k=0;k<j-i;k++){
                        tempthe.s[k]=$1[i+k];
                    }
                    tempthe.s[k]='\0';

                    for(k=0;k<n;k++){
                        if(strcmp(thes[k].s,tempthe.s) == 0){
                            thes[k].number++;
                        }
                    }
                    
                    i=j-1;
                }
            }

            for(i=0;i<strlen($4);i++){
                if('A'<=$4[i] && $4[i]<='Z'){
                    for(j=i+1;j<strlen($4);j++){
                        if('a'<=$4[j] && $4[j]<='z'){
                            continue;
                        }
                        else{
                            break;
                        }
                    }
                    
                    for(k=0;k<j-i;k++){
                        tempthe.s[k]=$4[i+k];
                    }
                    tempthe.s[k]='\0';

                    for(k=0;k<n;k++){
                        if(strcmp(thes[k].s,tempthe.s) == 0){
                            thes[k].number--;
                        }
                    }
                    
                    i=j-1;
                }
            }
            
            for(i=0;i<n;i++){
                if(thes[i].number != 0){
                    printf("%s %d\n",thes[i].s,thes[i].number);
                }
            }
        }
        ;
expr    :exps           {
            strcpy($$,$1);
        }
        |expr '+' exps  {
            strcpy($$,$1);
            strcat($$,$3);
        }
        ;
exps    :INUMBER exps   {
            strcpy($$,$2);
            for(i=1;i<$1;i++){
                strcat($$,$2);
            }
        }
        |'(' exps ')' INUMBER   {
            strcpy($$,$2);
            for(i=1;i<$4;i++){
                strcat($$,$2);
            }
        }
        |'(' exps ')'           {
            strcpy($$,$2);
        }
        |exps exps      {
            strcpy($$,$1);
            strcat($$,$2);
        }
        |expf           {
            strcpy($$,$1);
        }
        ;
expf    :expw           {
            finded=0;
            for(i=0;i<n;i++){
                if(strcmp(thes[i].s,$1)==0){
                    finded=1;
                    break;
                }
            }
            if(finded==0){
                strcpy(thes[n].s,$1);
                thes[n].number=0;
                n++;
            }
            strcpy($$,$1);
        }
        |expf INUMBER   {
            strcpy($$,$1);
            for(i=1;i<$2;i++){
                strcat($$,$1);
            }
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