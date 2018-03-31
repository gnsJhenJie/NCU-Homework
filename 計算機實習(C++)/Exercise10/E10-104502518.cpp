#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int x,i=0,j=0,n,a[10][10]={0},d=0;      //declare variable
    cout<<"Please input your number : ";
    cin>>n;     //input number
    for(i=0;i<n;i++){       //initiate n*n square
        for(j=0;j<n;j++){
            a[i][j]=1;
        }
    }
    i=j=0;
    for(x=1;x<=n*n;x++){        //give number to square
        if(d%4==0){
            if(a[i][j]==1&&j<n){
                a[i][j]=x;
                j++;
            }
            else{
                j--;
                d++;
                i++;
            }
        }
        if(d%4==1){
            if(a[i][j]==1&&i<n){
                a[i][j]=x;
                i++;
            }
            else{
                i--;
                d++;
                j--;
            }
        }
        if(d%4==2){
            if(j>=0){
                if(a[i][j]==1){
                    a[i][j]=x;
                    j--;
                }
                else{
                    d++;
                    j++;
                    i--;
                }
            }
            else{
                d++;
                j++;
                i--;
            }
        }
        if(d%4==3){
            if(a[i][j]==1&&i>0){
                a[i][j]=x;
                i--;
            }
            else{
                i++;
                d++;
                x--;
                j++;
            }
        }
    }
    for(i=0;i<n;i++){       //output the square
        for(j=0;j<n;j++){
            cout<<setw(4)<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
