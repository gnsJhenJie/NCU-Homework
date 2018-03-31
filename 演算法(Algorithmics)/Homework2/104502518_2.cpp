#include<iostream>
#include<cstring>
using namespace std;
int TheCount=0;

void Score(string &s1,string &s2,int startx,int starty,int endx,int endy,int &x,int &y){
    int len=endy-starty+1;
    int column1[len]={0};
    int column2[len]={0};
    int tempcol[len]={0};
    int mid=((endx-startx)/2)+startx;
    /*左半段*/
    /*初始化第一行*/
    /*初始化第一格*/
    if(s2[startx]==s1[starty]){
        column1[0]=1;
    }
    for(int j=1;j<len;j++){
        if(s2[startx]==s1[starty+j]){
            column1[j]=1;
        }
        else{
            column1[j]=column1[j-1];
        }
    }
    /*開始計算第二行*/
    if(startx==mid){
        for(int j=0;j<len;j++){
            column2[j]=column1[j];
        }
    }
    for(int i=startx+1;i<=mid;i++){
        /*初始化第一格*/
        if(s2[i]==s1[starty]){
            column2[0]=1;
        }
        else{
            column2[0]=column1[0];
        }
        for(int j=1;j<len;j++){
            if(s2[i]==s1[starty+j]){
                column2[j]=column1[j-1]+1;
            }
            else{
                if(column2[j-1]>column1[j]){
                    column2[j]=column2[j-1];
                }
                else{
                    column2[j]=column1[j];
                }
            }
        }
        for(int j=0;j<len;j++){
            column1[j]=column2[j];
        }
    }
    /*儲存值*/
    for(int j=0;j<len;j++){
        tempcol[j]+=column2[j];
        column1[j]=0;
        column2[j]=0;
    }
    /*右半段*/
    /*初始化第一行*/
    /*初始化第一格*/
    if(s2[endx]==s1[starty+len-1]){
        column1[len-1]=1;
    }
    for(int j=len-2;j>=0;j--){
        if(s2[endx]==s1[starty+j]){
            column1[j]=1;
        }
        else{
            column1[j]=column1[j+1];
        }
    }
    /*開始計算第二行*/
    if(endx-1==mid){
        for(int j=0;j<len;j++){
            column2[j]=column1[j];
        }
    }
    for(int i=endx-1;i>mid;i--){
        /*初始化第一格*/
        if(s2[i]==s1[starty+len-1]){
            column2[len-1]=1;
        }
        else{
            column2[len-1]=column1[len-1];
        }
        for(int j=len-2;j>=0;j--){
            if(s2[i]==s1[starty+j]){
                column2[j]=column1[j+1]+1;
            }
            else{
                if(column2[j+1]>column1[j]){
                    column2[j]=column2[j+1];
                }
                else{
                    column2[j]=column1[j];
                }
            }
        }
        for(int j=0;j<len;j++){
            column1[j]=column2[j];
        }
    }
    /*儲存值*/
    for(int j=1;j<len;j++){
        tempcol[j-1]+=column2[j];
    }
    /*設定回xy*/
    x=mid;
    int highest=-1;
    for(int j=0;j<len;j++){
        if(tempcol[j]>highest){
            highest=tempcol[j];
            y=starty+j;
        }
    }
    if(column2[0]>highest){
        y=starty-1;
    }
}

void Hirschberg(string &s1,string &s2,int startx,int starty,int endx,int endy){
    int x,y,tt;
    Score(s1,s2,startx,starty,endx,endy,x,y);

    if(x!=startx&&y!=starty&&startx+1!=x&&starty+1!=y&&x>startx&&y>starty){
        Hirschberg(s1,s2,startx,starty,x,y);
    }
    else if(x==startx){
        /*找Y方向*/
        for(int j=starty;j<=y;j++){
            if(s2[x]==s1[j]){
                cout<<s2[x];
                TheCount++;
                break;
            }
        }
    }
    else if(y==starty){
        /*找X方向*/
        for(int i=startx;i<=x;i++){
            if(s1[y]==s2[i]){
                cout<<s1[y];
                TheCount++;
                break;
            }
        }
    }
    else if(x-1==startx){
        /*找Y方向兩個*/
        tt=starty;
        for(int j=starty;j<=y;j++){
            if(s2[startx]==s1[j]){
                cout<<s2[startx];
                TheCount++;
                tt=j+1;
                break;
            }
        }
        for(int j=tt;j<=y;j++){
            if(s2[x]==s1[j]){
                cout<<s2[x];
                TheCount++;
                break;
            }
        }
    }
    else if(y-1==starty){
        /*找X方向兩個*/
        tt=startx;
        for(int i=startx;i<=x;i++){
            if(s1[starty]==s2[i]){
                cout<<s1[starty];
                TheCount++;
                tt=i+1;
                break;
            }
        }
        for(int i=tt;i<=x;i++){
            if(s1[y]==s2[i]){
                cout<<s1[y];
                TheCount++;
                break;
            }
        }
    }
    /*..........*/
    if(x+1!=endx&&y+1!=endy&&x+2!=endx&&y+2!=endy&&x+1<endx&&y+1<endy){
        Hirschberg(s1,s2,x+1,y+1,endx,endy);
    }
    else if(x+1==endx){
        /*找Y方向*/
        for(int j=y+1;j<=endy;j++){
            if(s2[x+1]==s1[j]){
                cout<<s2[x+1];
                TheCount++;
                break;
            }
        }
    }
    else if(y+1==endy){
        /*找X方向*/
        for(int i=x+1;i<=endx;i++){
            if(s1[y+1]==s2[i]){
                cout<<s1[y+1];
                TheCount++;
                break;
            }
        }
    }
    else if(x+2==endx){
        /*找Y方向兩個*/
        tt=y+1;
        for(int j=y+1;j<=endy;j++){
            if(s2[x+1]==s1[j]){
                cout<<s2[x+1];
                TheCount++;
                tt=j+1;
                break;
            }
        }
        for(int j=tt;j<=endy;j++){
            if(s2[x+2]==s1[j]){
                cout<<s2[x+2];
                TheCount++;
                break;
            }
        }
    }
    else if(y+2==endy){
        /*找X方向兩個*/
        tt=x+1;
        for(int i=x+1;i<=endx;i++){
            if(s1[y+1]==s2[i]){
                cout<<s1[y+1];
                TheCount++;
                tt=i+1;
                break;
            }
        }
        for(int i=tt;i<=endx;i++){
            if(s1[y+2]==s2[i]){
                cout<<s1[y+2];
                TheCount++;
                break;
            }
        }
    }
    /*..........*/
}

void submain(){
    string s1,s2,tempstr;
    int length1,length2;
    cin>>s1;
    cin>>s2;
    length1=s1.length();
    length2=s2.length();
    if(length1>length2){
        tempstr=s2;
        s2=s1;
        s1=tempstr;
        length1=s1.length();
        length2=s2.length();
    }
    Hirschberg(s1,s2,0,0,length2-1,length1-1);
}

int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;t++){
        TheCount=0;
        submain();
        cout<<endl;
        //cout<<"LCS Length: "<<TheCount<<endl;
    }

}
