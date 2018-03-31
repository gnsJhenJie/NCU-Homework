#include<iostream>
using namespace std;
struct number{
    int n;
    number *next;
}a[3];
int main(){
    cout<<"please input: ";
    int i;
    for(i=0;i<3;i++){
        cin>>a[i].n;
        if(i==0){
            a[i].next=NULL;
        }
        else{
            a[i].next=&a[i-1];
        }
    }
    cout<<endl<<a[2].n;
    for(i=2;i>=0;i--){
        if(a[i].next!=NULL){
            cout<<" "<<a[i].next->n;
        }
    }
    cout<<endl;
    return 0;
}
