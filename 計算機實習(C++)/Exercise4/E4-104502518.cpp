#include<iostream>
using namespace std;
int main(){
    int height,i,j;
    cout<<"please input height:";
    while(cin>>height){     //input height if ^Z stop program can input repeatedly
        cout<<"height is "<<height<<endl;
        for(i=1;i<=height;i++){     //1STloop start
            for(j=0;j<i;j++){
                cout<<"#";
            }
            cout<<"\n";
        }       //1ST loop over
        cout<<"\n";
        for(i=1;i<=height;i++){     //2ND loop start
            for(j=0;j<height-i;j++){
                cout<<" ";
            }
            for(j=0;j<i;j++){
                cout<<"#";
            }
            cout<<"\n";
        }       //2ND loop over
        cout<<"\n";
        cout<<"please input height:";
    }
    return 0;
}
