#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int i,j,ans,guess;
    for(i=1;i>0;i++){       //Round count
        srand(time(NULL));      //random number to ans
        ans=rand()%900+100;//ans 100~999
        cout<<"========== Round "<<i<<"==========\n"<<endl;     //output Round
        for(j=1;j<=5;j++){
            cout<<j<<" : please input your number:";
            cin>>guess;     //input guess
            if(guess==-1){      //if -1 stop program
                return 0;
            }
            if(guess==ans){     //correct
                cout<<"\nYou win !! The correct number is "<<ans<<endl<<endl;
                break;
            }
            if(j==5){       //lose
                cout<<"\nYou are a loser. The correct number is "<<ans<<endl<<endl;
                break;
            }
            else if(ans-guess>=100||ans-guess<=-100){       //guess wrong
                cout<<"The difference between ANS and Input is hundreds.\n\n";
            }
            else if(ans-guess>=10||ans-guess<=-10){     //guess wrong
                cout<<"The difference between ANS and Input is tens.\n\n";
            }
            else if(ans-guess<10||ans-guess>-10){       //guess wrong
                cout<<"The difference between ANS and Input is units.\n\n";
            }
        }
    }
}
