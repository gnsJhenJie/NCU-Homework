%option noyywrap
%{
int i;
%}
zzz    0
xxx    x|X
digita    [0-9]
digito    [1-9]
hhh    [a-fA-F]
id    ^[" "]*{zzz}{xxx}(({digito}({digita}|{hhh}){0,7})|({hhh}({digita}|{hhh}){0,7}))[" "]*$
%%
[\n\t]  {}
{id}  {for(i=0;i<yyleng;i++){if(yytext[i]!=' '){printf("%c",yytext[i]);}} printf("\n");}
.*  {}
%%
int main(int argc, char *argv[]){
    yylex();
    return(0);
}