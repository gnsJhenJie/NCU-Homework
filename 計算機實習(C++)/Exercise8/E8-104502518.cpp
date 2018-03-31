#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
void bubble(int a[]);
int main(){
    int i,a[10];        //declare variable
    cout<<endl;
    srand(time(NULL));
    for(i=0;i<10;i++){
        a[i]=rand()%100;        //random number *10
        cout<<setw(5)<<a[i];        //output 10 number
    }
    cout<<endl<<endl;
    bubble(a);
    return 0;
}
void bubble(int a[]){
    int x,i,j;
    for(j=0;j<9;j++){       //sort number
        for(i=0;i<9;i++){
            if(a[i]>a[i+1]){
                x=a[i];
                a[i]=a[i+1];
                a[i+1]=x;
            }
        }
    }
    for(i=0;i<10;i++){
        cout<<setw(5)<<a[i];        //output number after sort
    }
    cout<<endl;
}
