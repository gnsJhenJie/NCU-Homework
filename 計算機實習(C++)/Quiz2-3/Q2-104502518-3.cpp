#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
    string id[10],name[10],temps;       //declare variable
    int score[10],i,j,tempn,ranknumber=1;
    ifstream fin("input.txt");      //open txt
    for(i=0;i<10;i++){
        fin>>id[i]>>name[i]>>score[i];      //get data from txt
    }
    for(i=0;i<9;i++){       //bubble sort
        for(j=0;j<9-i;j++){
            if(score[j]<score[j+1]){
                tempn=score[j];
                score[j]=score[j+1];
                score[j+1]=tempn;
                temps=name[j];
                name[j]=name[j+1];
                name[j+1]=temps;
                temps=id[j];
                id[j]=id[j+1];
                id[j+1]=temps;
            }
        }
    }
    cout<<"Rank\tName\tID\tScore\n";        //output result
    cout<<ranknumber<<"\t"<<name[0]<<"\t"<<id[0]<<"\t"<<score[0]<<endl;
    ranknumber++;
    for(i=1;i<10;i++){
        if(score[i]==score[i-1]){
            ranknumber--;
        }
        cout<<ranknumber<<"\t"<<name[i]<<"\t"<<id[i]<<"\t"<<score[i]<<endl;
        ranknumber++;
    }
    fin.close();        //close txt
    return 0;
}
