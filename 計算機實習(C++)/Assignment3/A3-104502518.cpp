#include<iostream>
using namespace std;
int main(){
    int number,n1=1,n2=1,n,i=0;     //declare variable
    cout<<"Please input the number:";
    cin>>number;        //input number
    if(number<1){       //judge number<1
        cout<<"Number can't be less than 1";
    }
    else if(number==1){     //if number only 1
        cout<<"1";
    }
    else{
            cout<<"1 1 ";
        while(i<number-2){      //calculate two number sum and change side
            n=n2;
            n2=n1+n2;       //n2 is two number sum
            n1=n;
            cout<<n2<<" ";      //output sum;
            i++;        //count
        }
    }
    return 0;
}
