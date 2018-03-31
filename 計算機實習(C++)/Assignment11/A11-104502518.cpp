#include<iostream>
#include<cstring>
#include<fstream>
void route(char b[6][10],int,int);
void finder(char b[6][10],int,int,char);
void backstep(char b[6][10],int,int,char);
void route1(char b[6][10],int,int);
using namespace std;
int x,y;
int main(){
    char a[6][10],b[6][10];
    int step,i,j;
    ifstream fin("maze.txt");       //get map from txt
    for(i=0;i<6;i++){
        for(j=0;j<10;j++){
            fin>>a[i][j];
        }
    }
    for(i=0;i<6;i++){       //copy map
        for(j=0;j<10;j++){
            b[i][j]=a[i][j];
        }
    }
    route(b,0,0);       //start run map
    ofstream fout("map.txt");
    for(i=0;i<6;i++){       //return route except x
        for(j=0;j<10;j++){
            if(b[i][j]!='x'){
                b[i][j]=a[i][j];
            }
        }
    }
    for(i=0;i<6;i++){       //make map to txt
        for(j=0;j<10;j++){
            fout<<b[i][j];
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
void route(char b[6][10],int i,int j){      //first run map
    int select=0;
    if(i>0&&b[i-1][j]=='0'){
        select++;
    }
    if(j>0&&b[i][j-1]=='0'){
        select++;
    }
    if(j<9&&b[i][j+1]=='0'){
        select++;
    }
    if(i<5&&b[i+1][j]=='0'){
        select++;
    }
    if(i==5&&j==9){
        b[i][j]='x';
    }
    else if(select==1){
        b[i][j]='x';
        if(j<9&&b[i][j+1]=='0'){
            route(b,i,j+1);
        }
        else if(i<5&&b[i+1][j]=='0'){
            route(b,i+1,j);
        }
        else if(i>0&&b[i-1][j]=='0'){
            route(b,i-1,j);
        }
        else if(j>0&&b[i][j-1]=='0'){
            route(b,i,j-1);
        }
    }
    else if(select>1){
        b[i][j]='2';
        if(i>0&&b[i-1][j]=='0'){
            finder(b,i-1,j,'3');
        }
        if(j>0&&b[i][j-1]=='0'){
            finder(b,i,j-1,'3');
        }
        if(j<9&&b[i][j+1]=='0'){
            finder(b,i,j+1,'3');
        }
        if(i<5&&b[i+1][j]=='0'){
            finder(b,i+1,j,'3');
        }
    }
}
void finder(char b[6][10],int i,int j,char d){      //over one route run
    int select=0;
    if(i>0&&b[i-1][j]=='0'){
        select++;
    }
    if(j>0&&b[i][j-1]=='0'){
        select++;
    }
    if(j<9&&b[i][j+1]=='0'){
        select++;
    }
    if(i<5&&b[i+1][j]=='0'){
        select++;
    }
    if(i==5&&j==9){
        backstep(b,5,9,d);
    }
    else if(select==1){
        b[i][j]=d;
        if(j<9&&b[i][j+1]=='0'){
            finder(b,i,j+1,d);
        }
        else if(i<5&&b[i+1][j]=='0'){
            finder(b,i+1,j,d);
        }
        else if(i>0&&b[i-1][j]=='0'){
            finder(b,i-1,j,d);
        }
        else if(j>0&&b[i][j-1]=='0'){
            finder(b,i,j-1,d);
        }
    }
    else if(select>1){
        b[i][j]=d;
        if(i>0&&b[i-1][j]=='0'){
            finder(b,i-1,j,d+1);
        }
        if(j>0&&b[i][j-1]=='0'){
            finder(b,i,j-1,d+1);
        }
        if(j<9&&b[i][j+1]=='0'){
            finder(b,i,j+1,d+1);
        }
        if(i<5&&b[i+1][j]=='0'){
            finder(b,i+1,j,d+1);
        }
    }
    else{
        b[i][j]=d;
    }
}
void backstep(char b[6][10],int i,int j,char d){        //back from the end
    if(d=='2'){
        route1(b,i,j);
        x=i;
        y=j;
    }
    else{
        if(i>0&&b[i-1][j]==d-1){/**/
            b[i][j]='0';
            backstep(b,i-1,j,d-1);
        }
        else if(j>0&&b[i][j-1]==d-1){
            b[i][j]='0';
            backstep(b,i,j-1,d-1);
        }
        else if(j<9&&b[i][j+1]==d-1){
            b[i][j]='0';
            backstep(b,i,j+1,d-1);
        }
        else if(i<5&&b[i+1][j]==d-1){
            b[i][j]='0';
            backstep(b,i+1,j,d-1);
        }
        else if(i>0&&b[i-1][j]==d){
            b[i][j]='0';
            backstep(b,i-1,j,d);
        }
        else if(j>0&&b[i][j-1]==d){
            b[i][j]='0';
            backstep(b,i,j-1,d);
        }
        else if(j<9&&b[i][j+1]==d){
            b[i][j]='0';
            backstep(b,i,j+1,d);
        }
        else if(i<5&&b[i+1][j]==d){
            b[i][j]='0';
            backstep(b,i+1,j,d);
        }
    }
}
void route1(char b[6][10],int i,int j){     //second run to end
    if(i==5&&j==9){
        b[i][j]='x';
    }
    else if(j<9&&b[i][j+1]=='0'){
        b[i][j]='x';
        route1(b,i,j+1);
    }
    else if(i<5&&b[i+1][j]=='0'){
        b[i][j]='x';
        route1(b,i+1,j);
    }
    else if(i>0&&b[i-1][j]=='0'){
        b[i][j]='x';
        route1(b,i-1,j);
    }
    else if(j>0&&b[i][j-1]=='0'){
        b[i][j]='x';
        route1(b,i,j-1);
    }
}
