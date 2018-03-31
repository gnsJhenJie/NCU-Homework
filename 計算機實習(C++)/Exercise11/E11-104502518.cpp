#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("input.txt");
    int i,j,scorerank=1,scorenumber[7]={0},x;       //declare variable
    string id[7],name[7],score[7],y;
    if(!fin){
        cout<<"Fail to open file: input.txt\n";
    }
    for(i=0;i<7;i++){       //get data from txt
        fin>>id[i]>>name[i]>>score[i];
    }
    for(i=0;i<7;i++){       //get score number from string
        j=0;
        while(score[i][j]!='\0'){
            scorenumber[i]=scorenumber[i]*10+(score[i][j]-48);
            j++;
        }
    }
    for(i=0;i<6;i++){       //sort
        for(j=0;j<6-i;j++){
            if(scorenumber[j]<scorenumber[j+1]){
                x=scorenumber[j];
                scorenumber[j]=scorenumber[j+1];
                scorenumber[j+1]=x;
                y=id[j];
                id[j]=id[j+1];
                id[j+1]=y;
                y=name[j];
                name[j]=name[j+1];
                name[j+1]=y;
            }
        }
    }
    ofstream fout("output.txt");        //new txt
    fout<<"Rank\tName\tID\tScore\n";
    if(scorenumber[0]<0){       //everybody cheat
        fout<<"X\t"<<name[0]<<"\t"<<id[0]<<"\tcheat\n";
    }
    else{
        fout<<1<<"\t"<<name[0]<<"\t"<<id[0]<<"\t"<<scorenumber[0]<<endl;
    }
    for(i=1;i<7;i++){
        scorerank++;
        if(scorenumber[i]<0){       //who cheat
            fout<<"X\t"<<name[i]<<"\t"<<id[i]<<"\tcheat\n";
        }
        else if(scorenumber[i]==scorenumber[i-1]){      //same rank
            scorerank--;
            fout<<scorerank<<"\t"<<name[i]<<"\t"<<id[i]<<"\t"<<scorenumber[i]<<endl;
        }
        else{       //normal mode
            fout<<scorerank<<"\t"<<name[i]<<"\t"<<id[i]<<"\t"<<scorenumber[i]<<endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
