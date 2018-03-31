#include<iostream>
using namespace std;
struct child{       //declare struct
    int dir=0;
    int yesno=0;
}a[1000];
int main(){
    int l,n,i,x,step=0;
    while(1){
        cin>>l>>n;      //input line length and number of child
        if(l==-1&&n==-1){
            return 0;       //end
        }
        for(i=0;i<n;i++){
            cin>>x;     //input child site
            a[x].yesno=1;       //note people is there
            if(x>l/2){
                if((l-x)>step){
                    step=l-x;       //get min time
                }
            }
            else{
                if((x-1)>step){
                    step=x-1;       //get min time
                }
            }
        }
        cout<<"Min time:"<<step<<endl;      //output min time

        cout<<"Max time:"<<step<<endl<<endl;        //output max time
    }
}
