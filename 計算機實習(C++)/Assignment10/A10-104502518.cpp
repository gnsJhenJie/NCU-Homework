#include<iostream>
using namespace std;
int a[1000][1000]={0};      //declare 2D-array
void area (int a[][1000],int,int,int,int);      //declare function
int main(){
    int w,l,i,j,n=0;        //declart variable
    cout<<"Please input a two-dimensional array (row column) : ";
    cin>>w>>l;      //input wide*length
    cout<<"Fill the 2d array : \n";
    for(i=0;i<w;i++){
        for(j=0;j<l;j++){
            cin>>a[i][j];       //input array
        }
    }
    for(i=0;i<w;i++){       //get the area side
        for(j=0;j<l;j++){
            if(a[i][j]==1){
                n++;
                area(a,i,j,w,l);
            }
        }
    }
    cout<<"\nRegion's count : "<<n;
    return 0;
}
void area (int a[][1000],int i,int j,int w,int l){      //find area range and hide
    a[i][j]=0;
    if(i>0&&j>0){
        if(a[i-1][j-1]==1){
            area(a,i-1,j-1,w,l);
        }
    }
    if(i>0){
        if(a[i-1][j]==1){
            area(a,i-1,j,w,l);
        }
    }
    if(i>0&&j<l){
        if(a[i-1][j+1]==1){
            area(a,i-1,j+1,w,l);
        }
    }
    if(j>0){
        if(a[i][j-1]==1){
            area(a,i,j-1,w,l);
        }
    }
    if(j<l){
        if(a[i][j+1]==1){
            area(a,i,j+1,w,l);
        }
    }
    if(i<w&&j>0){
        if(a[i+1][j-1]==1){
            area(a,i+1,j-1,w,l);
        }
    }
    if(i<w){
        if(a[i+1][j]==1){
            area(a,i+1,j,w,l);
        }
    }
    if(i<w&&j<l){
        if(a[i+1][j+1]==1){
            area(a,i+1,j+1,w,l);
        }
    }
}
