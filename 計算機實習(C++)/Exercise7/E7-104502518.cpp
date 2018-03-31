#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int main(){
    int customer[4],dealer[4],i,in=1,custom,deal;       //declare variable
    srand(time(NULL));      //make random number
    cout<<"Do you want to play?(1:yes 0:no):";
    while(in==1){
        cin>>in;        //input 1 to continue 0 to end
        if(in==0){
            return 0;
        }
        for(i=0;i<4;i++){       //random number
            customer[i]=rand()%6+1;
        }
        sort(customer,customer+4);          //sort 4 number
        cout<<"Customer's point: ";
        for(i=0;i<4;i++){
            cout<<customer[i]<<" ";     //output customer number
        }
        for(i=0;i<4;i++){       //random number
            dealer[i]=rand()%6+1;
        }
        sort(dealer,dealer+4);      //sort 4 number
        cout<<"\nDealer's point: ";
        for(i=0;i<4;i++){
            cout<<dealer[i]<<" ";       //output dealer number
        }
        cout<<endl;
        if(customer[0]==customer[1]){       //find same number
            custom=customer[2]+customer[3];
        }
        else if(customer[1]==customer[2]){
            custom=customer[0]+customer[3];
        }
        else if(customer[2]==customer[3]){
            custom=customer[0]+customer[1];
        }
        else {
            cout<<"This time doesn't count.\n\n";
            cout<<"Do you still want to play?(1:yes 0:no):";
            continue;
        }
        if(dealer[0]==dealer[1]){       //find same number
            deal=dealer[2]+dealer[3];
        }
        else if(dealer[1]==dealer[2]){
            deal=dealer[0]+dealer[3];
        }
        else if(dealer[2]==dealer[3]){
            deal=dealer[0]+dealer[1];
        }
        else {
            cout<<"This time doesn't count.\n\n";
            cout<<"Do you still want to play?(1:yes 0:no):";
            continue;
        }
        cout<<"\n\nCustomer's point: "<<custom<<endl;       //output two point
        cout<<"Dealer's point: "<<deal<<endl;
        if(custom>deal){        //output result
            cout<<"\nCustomer wins!\n\n";
        }
        if(custom<deal){
            cout<<"\nDealer wins!QQ\n\n";
        }
        if(custom==deal){
            cout<<"\nEven\n\n";
        }
        cout<<"Do you still want to play?(1:yes 0:no):";
    }
}
