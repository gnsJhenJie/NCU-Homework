#include<iostream>
using namespace std;
int main(){
    int height,i,j;
    cout<<"please input height:";
    while(cin>>height){     //input rhombus height repeatedly
        if(height<0){
            break;
        }
        cout<<"height is "<<height<<endl;       //output rhombus height
        for(i=1;i<=height;i++){     //the first rhombus top triangle
            for(j=0;j<height-i;j++){
                cout<<" ";
            }
            for(j=0;j<i*2-1;j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        for(i=1;i<height;i++){      //the first rhombus bottom triangle
            for(j=0;j<i;j++){
                cout<<" ";
            }
            for(j=0;j<(height-i)*2-1;j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        cout<<"\n";
        for(i=1;i<=height;i++){     //the second rhombus top triangle
            for(j=0;j<height-i;j++){
                cout<<" ";
            }
            for(j=0;j<i;j++){
                cout<<" #";
            }
            cout<<"\n";
        }
        for(i=1;i<height;i++){      //the second rhombus bottom triangle
            for(j=0;j<i;j++){
                cout<<" ";
            }
            for(j=0;j<height-i;j++){
                cout<<" #";
            }
            cout<<"\n";
        }
        cout<<"please input height:";
    }
    return 0;
}
