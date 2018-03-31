%option noyywrap
%{
int i;
%}
c1    [0-9]
c2    [1-9][0-9]
c3    1[0-9]{2}
c4    2[0-4][0-9]
c5    25[0-5]
clap    {c1}|{c2}|{c3}|{c4}|{c5}
id    {clap}\.{clap}\.{clap}\.{clap}
%%
[\n\t]  {}
{id} {
    printf("%s\n",yytext);
}
.  {}
%%
int main(int argc, char *argv[]){
	yylex();
	return(0);
}