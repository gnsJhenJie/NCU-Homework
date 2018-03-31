#include <iostream>
using namespace std;
int main(){
    int sum=1,n,i=1;        //declare variable
    cout<<"Please input the number:";
    cin>>n;     //input Number
    if(n<0){        //judge n<0
        cout<<"Number can't be less than 0!";
    }
    else if(n==0){      //judge n=0
        cout<<"0! is 1";
    }
    else{       //n>0
        while(i<=n){
            sum=sum*i;      //calculate sum
            i++;
        }
        cout<<n<<"! is "<<sum;      //output sum
    }

    return 0;
}
