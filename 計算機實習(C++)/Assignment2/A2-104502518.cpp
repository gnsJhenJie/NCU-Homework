#include<iostream>
using namespace std;
int main(){
    int n1,n2,n3,n;     //declare variable
    cout<<"Please input three integers <press ENTER to input one by one> :\n";
    cin>>n1>>n2>>n3;        //input variable
    if(n1>n2){      //sort start
        n=n1;
        n1=n2;
        n2=n;
    }
    if(n2>n3){
        n=n2;
        n2=n3;
        n3=n;
    }
    if(n1>n2){
        n=n1;
        n1=n2;
        n2=n;
    }       //sort over
    cout<<n3<<" > "<<n2<<" > "<<n1<<endl;     //output result

    return 0;
}
