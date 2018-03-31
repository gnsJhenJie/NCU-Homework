#include<iostream>
using namespace std;
int main(){
    int n,x=0,i=1,number1,number2;
    cin>>n;
    while(n!=0){
        while(1){
            x=x+i;
            if(n<=x){
                break;
            }
            i++;
        }
        n=i-(x-n);
        if(i%2==0){
            number1=n;
            number2=1+i-n;
        }
        if(i%2==1){
            number1=1+i-n;
            number2=n;
        }
        cout<<number1<<'/'<<number2<<endl<<endl;
        x=0;
        i=1;
        cin>>n;
    }
    return 0;
}
