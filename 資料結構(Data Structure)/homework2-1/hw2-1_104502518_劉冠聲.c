#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0;
typedef enum{lparen=1,rparen,plus,minus,times,divides,mod,eos,operand}precedence;
int isp[9]={0,20,13,13,17,17,17,-1,5};
int icp[9]={20,19,13,13,17,17,17,-1,5};
int now=0;
char infix[200];
char output;
char change[200];
int changenow;

precedence stack[100];

void push(precedence data){
    now++;
    stack[now]=data;
}
char pop(void){
    char temp;
    switch(stack[now]){
        case lparen : temp='(';break;
        case rparen : temp=')';break;
        case plus : temp='+';break;
        case minus : temp='-';break;
        case divides : temp='/';break;
        case times : temp='*';break;
        case mod : temp='%';break;
        default : temp=' ';
    }
    now--;
    return temp;
}

precedence get_token(char *symbol, int *n){
    *symbol=infix[(*n)++];
    switch(*symbol){
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '/' : return divides;
        case '*' : return times;
        case '%' : return mod;
        case ' ' : return eos;
        default : return operand;
    }
}
void postfix(void){
    char symbol;
    precedence token;
    int n = 0;
    int top=0;
    stack[0]=eos;
    for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n)){
        if(token==operand){
            change[changenow]=symbol;
            changenow++;
            printf("%c",symbol);
        }
        else if(token==rparen){
            while(stack[now]!=lparen){
                change[changenow]=pop();
                changenow++;
                now++;
                printf("%c",pop());
            }
            now--;
        }
        else{
            while(isp[stack[now]-1]>=icp[token-1]){
                change[changenow]=pop();
                changenow++;
                now++;
                printf("%c",pop());
            }
            push(token);
        }
    }
    while(stack[now]!=eos){
        change[changenow]=pop();
        changenow++;
        now++;
        printf("%c",pop());
    }
    printf("\n");
}

int setwhere=0;
int set[50];
void setin(int data){
    setwhere++;
    set[setwhere]=data;

}
int setout(void){
    int temp;
    temp=set[setwhere];
    setwhere--;
    return temp;
}
void setwow(char data){
    int temp1,temp2;
    temp1=setout();
    temp2=setout();
    if(data=='+'){
        setin(temp2+temp1);
    }
    else if(data=='-'){
        setin(temp2-temp1);
    }
    else if(data=='*'){
        setin(temp2*temp1);
    }
    else if(data=='/'){
        setin(temp2/temp1);
    }
}

void main(){
    char str[200];
    char wow[200];
    scanf("%s",&str);
    int i;
    for(i=0;i<=strlen(str);i++){
        if(i==strlen(str)){
            infix[i]=' ';
            infix[i+1]='\0';
        }
        else{
            infix[i]=str[i];
        }
    }
    postfix();
    /**/
    for(i=0;i<strlen(change);i++){
        switch(change[i]){
            case '+' : setwow('+');break;
            case '-' : setwow('-');break;
            case '/' : setwow('/');break;
            case '*' : setwow('*');break;
            default : setin(change[i]-'0');
        }
    }
    printf("最後結果:%d",setout());
}
