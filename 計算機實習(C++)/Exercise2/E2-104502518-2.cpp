#include<iostream>
using namespace std;
int main(){
    int n1,n2,n3,n;     //declare variable
    cout<<"Input your 3 numbers:\n";
    cin>>n1>>n2>>n3;    //input variable
    if(n1>=n2){     //arrange in order start
        n=n1;
        n1=n2;
        n2=n;
    }
    if(n2>=n3){
        n=n2;
        n2=n3;
        n3=n;
    }
    if(n1>=n2){
        n=n1;
        n1=n2;
        n2=n;
    }       //arrange in order over
    if(n1+n2>n3){       //judge triangle
        if(n1==n2||n2==n3||n1==n3){     //judge Isosceles triangle
            cout<<"Isosceles triangle";
        }
        else if((n1*n1)+(n2*n2)==(n3*n3)){      //judge Rectangular triangle
            cout<<"Rectangular triangle";
        }
        else{
            cout<<"triangle";
        }
    }
    else{       //not triangle
        cout<<"This isn't a triangle";
    }

    return 0;
}

