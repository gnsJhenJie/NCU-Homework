#include<iostream>
using namespace std;
int main(){
    int n,a[1000]={0},i,wall=0,moves=0,average=0;       //declare variable
    cout<<"number of walls : ";
    cin>>n;     //get first wall number
    while(n!=0){        //judge wall exist
        cout<<"brick number of each wall : ";
        for(i=0;i<n;i++){       //input each wall height
            cin>>a[i];
            wall=wall+a[i];     //count sum of wall height
        }
        average=wall/n;     //count average of wall
        for(i=0;i<n;i++){
            if(a[i]>average){
                moves=moves+a[i]-average;       //count move time
            }
        }
        cout<<"minimum number of moves is : "<<moves<<endl<<endl;       //output result
        moves=wall=0;
        cout<<"number of walls : ";
        cin>>n;
    }
    cout<<"exit";       //program over
    return 0;
}
