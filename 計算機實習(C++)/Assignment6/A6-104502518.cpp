#include<iostream>
using namespace std;
int gcd(int,int);       //declare function
int lcm(int,int);
int power(int,int);
int maxy,miny;
int main(){
    int mode,number1,number2,result;        //declare variable
    while(1){
        cout<<"===========================\n";
        cout<<"(1) Greatest Common Divisor\n";
        cout<<"(2) Least Common Multiple\n";
        cout<<"(3) Power\n";
        cout<<"(4) Exit\n";
        cout<<"Select a action: ";
        cin>>mode;      //select action
        if(mode==4){
            return 0;
        }
        cout<<"Please input two integers:\n";       //input two number
        cin>>number1>>number2;
        if(number1>number2){
            maxy=number1;
            miny=number2;
        }
        if(number2>number1){
            maxy=number2;
            miny=number1;
        }
        switch (mode){      //do action and call function
            case 1:
                result=gcd(number1,number2);
                cout<<"The ged of two integers is: "<<result<<endl;     //output the result
                break;
            case 2:
                result=lcm(number1,number2);
                cout<<"The lem of two integers is: "<<result<<endl;     //output the result
                break;
            case 3:
                result=power(number1,number2);
                cout<<number1<<" ^ "<<number2<<" is "<<result<<endl;    //output the result
                break;
        }
    }
}
int gcd(int n1,int n2){     //function to GCD
    int x;
    if(n1>n2){
        x=n1-n2;
        if(miny%x==0){
            return x;
        }
        return gcd(n2,x);
    }
    if(n2>n1){
        x=n2-n1;
        if(miny%x==0){
            return x;
        }
        return gcd(n1,x);
    }
}
int lcm(int n1,int n2){     //function to LCM
    if(n1>n2){
        if((n1-n2)%miny==0){
            return n1;
        }
        return lcm(n1+maxy,n2+miny);
    }
    if(n2>n1){
        if((n2-n1)%miny==0){
            return n2;
        }
        return lcm(n1+miny,n2+maxy);
    }
    return n1;
}
int power(int n1,int n2){       //function to POWER
    if(n2==0||n2==1){
        return 1;
    }
    return n1*power(n1,n2-1);
}
