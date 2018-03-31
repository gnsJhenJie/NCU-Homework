#include<iostream>
using namespace std;
long long int function1(int);
int main(){
    int n,digit=0;
    long long int number;
    do{
        cout<<"Please input a number (enter -1 to exit): ";
        cin>>n;
        if(n==-1){
            cout<<"bye~\n";
            return 0;
        }
        number=function1(n);
        cout<<n<<" != "<<number<<", ";
        while(number!=0){
            number=number/10;
            digit++;
        }
        cout<<digit<<" digits\n\n";
        digit=0;
    }while(n>0);
}
long long int function1(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*function1(n-1);
}
