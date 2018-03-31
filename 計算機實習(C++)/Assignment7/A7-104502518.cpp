#include<iostream>
#include<cmath>
using namespace std;
int movetime(int);      //function for count time
void tower(int);        //function for output the move step
int sblock(int,int);        //founction for move rule1
int counting1(int x);       //function for move rule2
int main(){     //main function
    int number;
    while(1){
        cout<<"�п�J����(��J0����):";
        cin>>number;
        if(number==0){
            return 0;
        }
        tower(number);
        cout<<"�`�@���ʤF"<<movetime(number)-1<<"��\n\n";
    }
}
int movetime(int n){        //calculate move time
    if(n==0){
        return 1;
    }
    return 2*movetime(n-1);
}
void tower(int n){      //output every step when moving the block
    int i,j;
    if(n==1){       //condition 1block
        cout<<"�N��1�Ӷ�L�qA����C\n";
    }
    if(n==2){       //condition 2blocks
        cout<<"�N��1�Ӷ�L�qA����B\n";
        cout<<"�N��2�Ӷ�L�qA����C\n";
        cout<<"�N��1�Ӷ�L�qB����C\n";
    }
    if(n==3){       //condition 3blocks
        cout<<"�N��1�Ӷ�L�qA����C\n";
        cout<<"�N��2�Ӷ�L�qA����B\n";
        cout<<"�N��1�Ӷ�L�qC����B\n";
        cout<<"�N��3�Ӷ�L�qA����C\n";
        cout<<"�N��1�Ӷ�L�qB����A\n";
        cout<<"�N��2�Ӷ�L�qB����C\n";
        cout<<"�N��1�Ӷ�L�qA����C\n";
    }
    if(n>3){        //condition more than 3block
        tower(n-2);
        if(n%2==0){     //condition block is even
            cout<<"�N��"<<n-1<<"�Ӷ�L�qA����B\n";
            for(i=1;i<=(movetime(n)-movetime(n-2)-1);i++){
                if(i%4==1||i%4==3){
                    j=1;
                }
                if(i%4==2){
                    j=2;
                }
                if(i%4==0){
                    j=sblock(n,i/4);        //use rule1
                }
                if(i%3==1){
                    if(j%2==1){
                        cout<<"�N��"<<j<<"�Ӷ�L�qC����A\n";
                    }
                    else{
                        cout<<"�N��"<<j<<"�Ӷ�L�qA����C\n";
                    }
                }
                if(i%3==2){
                    if(j%2==1){
                        cout<<"�N��"<<j<<"�Ӷ�L�qB����C\n";
                    }
                    else{
                        cout<<"�N��"<<j<<"�Ӷ�L�qC����B\n";
                    }
                }
                if(i%3==0){
                    if(j%2==1){
                        cout<<"�N��"<<j<<"�Ӷ�L�qA����B\n";
                    }
                    else{
                        cout<<"�N��"<<j<<"�Ӷ�L�qB����A\n";
                    }
                }
            }
        }
        if(n%2==1){     //condition block is odd
            cout<<"�N��"<<n-1<<"�Ӷ�L�qA����B\n";
            for(i=1;i<=(movetime(n)-movetime(n-2))-1;i++){
                if(i%4==1||i%4==3){
                    j=1;
                }
                if(i%4==2){
                    j=2;
                }
                if(i%4==0){
                    j=sblock(n,i/4);        //use rule1
                }
                if(i%3==1){
                    if(j%2==1){
                        cout<<"�N��"<<j<<"�Ӷ�L�qC����B\n";
                    }
                    else{
                        cout<<"�N��"<<j<<"�Ӷ�L�qB����C\n";
                    }
                }
                if(i%3==2){
                    if(j%2==1){
                        cout<<"�N��"<<j<<"�Ӷ�L�qA����C\n";
                    }
                    else{
                        cout<<"�N��"<<j<<"�Ӷ�L�qC����A\n";
                    }
                }
                if(i%3==0){
                    if(j%2==1){
                        cout<<"�N��"<<j<<"�Ӷ�L�qB����A\n";
                    }
                    else{
                        cout<<"�N��"<<j<<"�Ӷ�L�qA����B\n";
                    }
                }
            }
        }
    }
}
int sblock(int n,int m){        //rule1
    if(m==pow(2,n-4)){
        return n;
    }
    if(n==4&&m==2){
        return 3;
    }
    if(m<pow(2,n-4)){
        return sblock(n-1,counting1(n-1)-m+1);//4156216521
    }
    if(m>pow(2,n-4)){
        if(m>pow(2,n-3)){
            return sblock(n-1,counting1(n-1)+pow(2,n-3)-m+1);
        }
        else{
            return sblock(n-1,counting1(n-1)-m+pow(2,n-4)+1);
        }
    }
}
int counting1(int x){       //rule2
    if(x==4){
        return 2;
    }
    return counting1(x-1)+3*(x-4);
}
