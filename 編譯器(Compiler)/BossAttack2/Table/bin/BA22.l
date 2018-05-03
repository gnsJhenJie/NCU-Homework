%option noyywrap
%{
#include<iostream>
#include<cstring>
using namespace std;
int i;
%}

name    [a-zA-Z0-9]+
email   ^{name}@{name}\.{name}(.{name})*$

capital [A-Z]
small   [a-zA-Z]*
word    ^{capital}{small}$

c1      [0-9]
c2      [1-9][0-9]
c3      1[0-9]{2}
c4      2[0-4][0-9]
c5      25[0-5]
clap    {c1}|{c2}|{c3}|{c4}|{c5}
ip      ^{clap}\.{clap}\.{clap}\.{clap}$
%%
[\n\t]  {}
{word}    {for(i=0;i<yyleng;i++){
            if(yytext[i]!=' '){
                cout<<yytext[i];
            }
        }
        cout<<" is a word"<<endl;}
{ip}    {for(i=0;i<yyleng;i++){
            if(yytext[i]!=' '){
                cout<<yytext[i];
            }
        }
        cout<<" is an IP address"<<endl;}
{email}    {for(i=0;i<yyleng;i++){
            if(yytext[i]!=' '){
                cout<<yytext[i];
            }
        }
        cout<<" is an email address"<<endl;}
.       {}
%%
int main(int argc, char *argv[]){
    yylex();
    return(0);
}