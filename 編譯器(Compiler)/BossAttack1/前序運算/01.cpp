#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
string s;
int cc,error;
string errorMessage;
bool can;

int stackoperation;
int stackint;
struct tokenoperation{
    char ts;
}operation[2000];
struct tokenint{
    int ti;
}iint[2000];

int judge(int n){
    if(n>=s.length()){
        return 100;
    }
    if(s[n]==-1){
        return 0;
    }
    else if(s[n]=='+'){
        return 1;
    }
    else if(s[n]=='-'){
        return 2;
    }
    else if(s[n]=='*'){
        return 3;
    }
    else if(s[n]=='/'){
        return 4;
    }
    else if(s[n]=='0'){
        return 5;
    }
    else if(s[n]<='9'&&s[n]>='1'){
        return 6;
    }
    else if(s[n]==' '){
        return 7;
    }
    else{
        return 404;
    }
}

void exp(){

}

void exps(){

}

void prog(){

}

void ReadFormula(){
    int i,j,error1,error2;
    for(i=0;i<s.length();i++){//тUnknown
        if(judge(i)==404){
            error=1;
            can=false;
            error2=i;
            if(i!=0){
                for(j=i-1;j>=0;j--){//程秨繷
                    if(judge(j)==5||judge(j)==6){
                        error1=j;
                        continue;
                    }
                    else if(judge(j)==1||judge(j)==2){
                        if(j==i-1){
                            error1=i;
                            break;
                        }
                        else{
                            error1=j;
                            break;
                        }
                    }
                    else if(judge(j)==7||judge(j)==3||judge(j)==4){
                        error1=j+1;
                        break;
                    }
                }
                for(j=i;j<s.length();j++){//程挡Ю
                    if(judge(j)!=1&&judge(j)!=2&&judge(j)!=3&&judge(j)!=4&&judge(j)!=7){
                        error2=j;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                error1=i;
                for(j=i;j<s.length();j++){//程挡Ю
                    if(judge(j)!=1&&judge(j)!=2&&judge(j)!=3&&judge(j)!=4&&judge(j)!=7){
                        error2=j;
                    }
                    else{
                        break;
                    }
                }
            }
            errorMessage=s.substr(error1,error2-error1+1);
            return;
        }
    }

    for(i=0;i<s.length();i++){//秨﹍穝糤token
        if(judge(i)==1||judge(i)==2){//笿+-
            if(judge(i+1)!=5&&judge(i+1)!=6){
                stackoperation++;
                operation[stackoperation].ts=s[i];
                continue;
            }
            else{
                for(j=i+1;j<s.length();j++){
                    if(judge(j)==5||judge(j)==6){
                        if(j==s.length()-1){
                            stackint++;
                            iint[stackint].ti=atoi(s.substr(i,s.length()-i).c_str());
                            i=s.length();
                            break;
                        }
                        continue;
                    }
                    else{
                        stackint++;
                        iint[stackint].ti=atoi(s.substr(i,j-i).c_str());
                        i=j-1;
                        break;
                    }
                }
            }
        }
        else if(judge(i)==3||judge(i)==4){//笿*/
            stackoperation++;
            operation[stackoperation].ts=s[i];
        }
        else if(judge(i)==5||judge(i)==6){//笿计
            for(j=i+1;j<s.length();j++){
                if(judge(j)!=5&&judge(j)!=6){
                    stackint++;
                    iint[stackint].ti=atoi(s.substr(i,j-i).c_str());
                    i=j-1;
                    break;
                }
                if(j==s.length()-1){
                    stackint++;
                    iint[stackint].ti=atoi(s.substr(i,s.length()-i).c_str());
                    i=s.length();
                    break;
                }
            }
        }


    }
}

void EvalFormula(){

}

void PrintErrorMessage(){
    if(error==1){
        //Unknown token
        cout<<"Error: Unknown token "<<errorMessage<<endl;
    }
    else if(error==2){
        //Divide by Zero
    }
    else if(error==3){
        //Illegal formula
    }
}

int main(){

    cc=0;
    can=true;
    stackoperation=0;
    stackint=0;

    while(getline(cin,s)){
        ReadFormula();
        if(can){
            /**/
            for(int i=1;i<=stackint;i++){
                cout<<iint[i].ti<<endl;
            }
            for(int i=1;i<=stackoperation;i++){
                cout<<operation[i].ts<<endl;
            }

            /**/
            EvalFormula();
            if(can){
                //output the result
            }
            else{
                PrintErrorMessage();
            }
        }
        else{
            PrintErrorMessage();
        }

        cc=0;
        can=true;
        stackoperation=0;
        stackint=0;

    }


    return 0;
}
