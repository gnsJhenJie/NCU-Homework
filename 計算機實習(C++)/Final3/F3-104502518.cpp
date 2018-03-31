#include<iostream>
using namespace std;
struct king{        //declare struct for people
    int tag=0;      //judge king
}a[10];
int main(){
    int n,x,i=0,people=0;       //declare variable
    cout<<"Please input n: ";
    cin>>n;     //input king number
    x=n;
    while(1){       //find king
        if(people==9){      //the last king
            for(i=0;i<10;i++){
                if(a[i].tag==0){
                    cout<<"The No."<<i+1<<" person is the last king.";
                    return 0;       //end
                }
            }
        }
        if(a[i].tag!=1){        //not king
            x--;
        }
        if(x==0){       //is king
            a[i].tag=1;
            people++;
            x=n;
        }
        i++;
        if(i==10){
            i=0;
        }

    }
}
