#include<iostream>
#include<cstring>
using namespace std;
string s;
int cc;
bool can;

void primary_tail();
void primary();
void exp();
void stmt();
void stmts();
void program();


int judge(int n){
    if(n>=s.length()){
        return 100;
    }

    if(s[n]==';'){
        return 0;
    }
    else if(s[n]=='.'){
        return 1;
    }
    else if(s[n]=='\"'){
        return 2;
    }
    else if(s[n]=='('){
        return 3;
    }
    else if(s[n]==')'){
        return 4;
    }
    else if(((s[n]<='z')&&(s[n]>='a'))||((s[n]<='Z')&&(s[n]>='A'))||(s[n]=='_')){
        return 5;
    }
    else if((s[n]<='9')&&(s[n]>='0')){
        return 6;
    }
    else if(s[n]==' '){
        return 7;
    }
    else{
        return 404;
    }
}


void primary_tail(){
    if(judge(cc)==100){
        return;
    }
    int i;
    if(judge(cc)==7){
        for(i=cc;i<s.length();i++){
            if(judge(i)!=7){
                cc=i;
                break;
            }
        }
    }
    if(judge(cc)==1){
        cout<<"DOT ."<<endl;
        cc++;
        for(i=cc;i<s.length();i++){
            if(judge(i)==5||judge(i)==6){
                continue;
            }
            else if(judge(i)==7||judge(i)==0||judge(i)==3||judge(i)==1){
                break;
            }
            else{
                cout<<"invalid input"<<endl;
                can=false;
                return;
            }
        }
        cout<<"ID "<<s.substr(cc,i-cc)<<endl;
        cc=i;
        primary_tail();
    }
    else if(judge(cc)==3){
        cout<<"LBR ("<<endl;
        cc++;
        exp();
        cout<<"RBR )"<<endl;
        cc++;
        primary_tail();
    }
    else{
        return;
    }
}

void primary(){
    if(judge(cc)==100){
        return;
    }
    int i;
    if(judge(cc)==7){
        for(i=cc;i<s.length();i++){
            if(judge(i)!=7){
                cc=i;
                break;
            }
        }
    }
    if(judge(cc)==5){
        for(i=cc;i<s.length();i++){
            if(judge(i)==5||judge(i)==6){
                continue;
            }
            else if(judge(i)==7||judge(i)==0||judge(i)==3||judge(i)==1){
                break;
            }
            else{
                cout<<"invalid input"<<endl;
                can=false;
                return;
            }
        }
    }
    else{
        cout<<"invalid input"<<endl;
        can=false;
        return;
    }
    cout<<"ID "<<s.substr(cc,i-cc)<<endl;
    cc=i;
    primary_tail();
}

void exp(){
    if(judge(cc)==100){
        return;
    }
    if(judge(cc)==7){
        for(int i=cc;i<s.length();i++){
            if(judge(i)!=7){
                cc=i;
                break;
            }
        }
    }
    if(judge(cc)==5){
        primary();
    }
    else if(judge(cc)==2){
        for(int i=cc+1;i<s.length();i++){
            if(judge(i)==2){
                if(i+1<s.length()){
                    cout<<"STRLIT \" "<<s.substr(cc+1,i-cc-1)<<" \""<<endl;
                    cc=i+1;
                }
                else{
                    cout<<"invalid input"<<endl;
                    can=false;
                    return;
                }
            }
        }
    }
    else{
        return;
    }

}

void stmt(){
    if(judge(cc)==100){
        return;
    }
    exp();
    if(!can){
        return;
    }
    if(judge(cc)==0){
        cout<<"SEMICOLON ;"<<endl;
        cc++;
    }
    else{
        cout<<"invalid input"<<endl;
        can=false;
        return;
    }
}

void stmts(){
    if(judge(cc)==100){
        return;
    }
    if(judge(cc)==7){
        for(int i=cc;i<s.length();i++){
            if(judge(i)!=7){
                cc=i;
                break;
            }
        }
    }
    if(judge(cc)==2||judge(cc)==5||judge(cc)==6){
        stmt();
        if(can){
            stmts();
        }
        else{
            return;
        }
    }
    else{
        cout<<"invalid input"<<endl;
        can=false;
        return;
    }
}

void program(){
    for(int i=s.length()-1;i>=0;i--){
        if(judge(i)==7){
            continue;
        }
        if(judge(i)==0){
            break;
        }
        else{
            cout<<"invalid input"<<endl;
            can=false;
            return;
        }
    }
    stmts();
}


int main(){
    cc=0;
    can=true;
    while(getline(cin,s)){
        program();
        cc=0;
        can=true;
        s="";
    }

    return 0;
}
