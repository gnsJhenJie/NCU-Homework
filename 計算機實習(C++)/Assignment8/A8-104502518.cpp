#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
void insertion(int a[]);
int main(){
    int i,a[10],x;        //declare variable
    cout<<endl;
    srand(time(NULL));
    for(i=0;i<10;i++){
        a[i]=rand()%100;        //random number *10
        cout<<setw(5)<<a[i];        //output 10 number
    }
    cout<<endl<<endl;
    insertion(a);
    return 0;
}
void insertion(int a[]){        //insertion sort
    int i,x,j;
    for(i=0;i<10;i++){
        x=a[i];
        for(j=i-1;j>=0;j--){
            if(x<a[j]){
                a[j+1]=a[j];
                a[j]=x;
            }
        }
    }
    for(i=0;i<10;i++){
        cout<<setw(5)<<a[i];        //output number after sort
    }
    cout<<endl;
}
