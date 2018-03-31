#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int i,j,ans,ansh,anst,ansu,guess,guessh,guesst,guessu,A=0,B=0;
    for(i=1;i>0;i++){       //Round count
        srand(time(NULL));
        do{
            ans=rand()%900+100;     //ans range:100~999
            ansh=ans/100;
            anst=(ans%100)/10;
            ansu=ans%10;
        }while(ansh==anst||anst==ansu||ansh==ansu);
        cout<<"========== Round "<<i<<"==========\n"<<endl;     //output Round
        for(j=1;j<=5;j++){
            A=B=0;
            cout<<"Input "<<j<<" : ";
            cin>>guess;
            if(guess==-1){      //input guess
                return 0;
            }
            guessh=guess/100;
            guesst=(guess%100)/10;
            guessu=guess%10;
            while(guessh==guesst||guesst==guessu||guessh==guessu){
                cout<<"Your input is wrong. Please input again.\n\n";
                cout<<"Input "<<j<<" : ";
                cin>>guess;     //input guess
                guessh=guess/100;
                guesst=(guess%100)/10;
                guessu=guess%10;
            }
            if(guessh==ansh){       //judge start
                A++;
            }
            else if(guessh==anst){
                B++;
            }
            else if(guessh==ansu){
                B++;
            }
            if(guesst==anst){
                A++;
            }
            else if(guesst==ansh){
                B++;
            }
            else if(guesst==ansu){
                B++;
            }
            if(guessu==ansu){
                A++;
            }
            else if(guessu==anst){
                B++;
            }
            else if(guessu==ansh){      //judge start
                B++;
            }
            cout<<"Result"<<j<<": "<<A<<"A"<<B<<"B\n\n";
            if(A!=3&&j==5){     //lose
                cout<<"Your are a loser\n\n";
                break;
            }
            if(A==3){       //win
                cout<<"You win !!\n\n";
                break;
            }
        }
    }
}
