#include<iostream>
using namespace std;
int main(){
    int a[10]={0},n,i,j;
    cout<<"Please input your number : ";
    cin>>n;
    cout<<endl<<"Your result :"<<endl<<endl<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==0){
                a[j]=j+1;
            }
            else if(i==n-1){
                a[j]=n+n-1+n-j-1;
            }
            else if(i==1){
                a[j]=j+n-2+n-1+n-1+n;
                if(j==n-1){
                    a[j]=n+i;
                }
            }
            else if(i==2){
                a[j]=n+j+2*(n-1+n-2+n-3);
                if(j==n-1){
                    a[j]=n+i;
                }
                if(j==0){
                    a[j]=n+n-1+n-1+n-3;
                }
                if(j==n-2){
                    a[j]=n+2*(n-1+n-2)+n-j-1;
                }
            }
            else{
                a[j]=0;
            }
            if(a[j]<10){
                cout<<"   ";
            }
            else if(a[j]<100){
                cout<<"  ";
            }
            else if(a[j]<1000){
                cout<<" ";
            }
            cout<<" "<<a[j];
        }
        cout<<endl;
    }
    return 0;
}
