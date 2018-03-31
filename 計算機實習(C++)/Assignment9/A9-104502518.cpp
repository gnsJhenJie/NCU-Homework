#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int digit(int);     //function for count digit
void putsign(int,int);      //function output sign -
int main(){
    string form;        //declare mathematical formula
    int i,j,number1=0,number2=0,wide,x,y,z;     //declare variable n1(砆埃计),n2(埃计),wide(糴),x(坝),z(程蔼计),y(程蔼计)
    cout<<"Please input your Mathematical formula : ";
    cin>>form;
    cout<<"Your Result:\n\n";
    for(i=0;i<form.length();i++){
        if(form[i]=='/'){
            for(j=0;j<i;j++){       //get two number
                number1=number1*10+(form[j]-48);
            }
            for(j=i+1;j<form.length();j++){
                number2=number2*10+(form[j]-48);
            }
            x=number1/number2;
            break;
        }
    }
    wide=digit(number2)+digit(number1)+3;
    cout<<setw(wide)<<x<<endl;
    putsign(number1*100,wide);
    cout<<number2<<" | "<<number1<<endl;
    while(number1>number2){     //out the graph of formula of /
        z=pow(10.0,digit(x)-1);
        y=x/z;
        for(i=0;i<wide-digit((number2*y)*z);i++){
            cout<<" ";
        }
        cout<<number2*y<<endl;
        putsign(number1,wide);
        number1=number1-(number2*y)*z;
        x=x%(y*z);
        cout<<setw(wide)<<number1<<endl;
    }
    return 0;
}
int digit(int n){
    int x=1;
    while(n>=10){
        n=n/10;
        x++;
    }
    return x;
}
void putsign(int n,int wide){
    int i;
    for(i=0;i<wide-digit(n);i++){
        cout<<" ";
    }
    for(i=0;i<digit(n);i++){
        cout<<"-";
    }
    cout<<endl;
}
