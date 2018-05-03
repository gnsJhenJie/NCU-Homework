%option noyywrap
%{
#include<iostream>
#include<cstring>
using namespace std;
int i;
%}
porn        [\+|-]
first       [1-9]
alldigit    [0-9]
bug         \.{alldigit}*

result      ^{porn}?({first}){1}{bug}?E{porn}?{first}{alldigit}*$
%%
[\n\t]  {}
{result}    {for(i=0;i<yyleng;i++){
            if(yytext[i]!=' '){
                cout<<yytext[i];
            }
        }
        cout<<endl;}
.       {}
%%
int main(int argc, char *argv[]){
    yylex();
    return(0);
}