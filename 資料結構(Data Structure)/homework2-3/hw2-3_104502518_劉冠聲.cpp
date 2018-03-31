#include<cstdlib>
#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;

void SetColor(int f=7,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

int now=0;
int exit_row,exit_col;
int maze[50][50];
int mark[50][50];
int i,j,rownum,colnum;

struct s
{
    int row;
    int col;
    int dir;
} position;

struct sta
{
    int row;
    int col;
    int dir;
} stackk[200];

void push(s where)
{
    now++;
    stackk[now].row=where.row;
    stackk[now].col=where.col;
    stackk[now].dir=where.dir;
}

s pop(void)
{
    s where;
    where.row=stackk[now].row;
    where.col=stackk[now].col;
    where.dir=stackk[now].dir;
    now--;
    return where;
}

int movevert(int dir)
{
    switch(dir)
    {
    case 0:
        return -1;
    case 1:
        return -1;
    case 2:
        return 0;
    case 3:
        return 1;
    case 4:
        return 1;
    case 5:
        return 1;
    case 6:
        return 0;
    case 7:
        return -1;
    }
}

int movehoriz(int dir)
{
    switch(dir)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 0;
    case 5:
        return -1;
    case 6:
        return -1;
    case 7:
        return -1;
    }
}

void path(void)
{
    int x,y,row,col,next_row,next_col,dir,found=0;
    mark[1][1]=1;
    stackk[0].row=1;
    stackk[0].col=1;
    stackk[0].dir=1;
    while((now>-1)&&(found==0))
    {
        position=pop();
        row=position.row;
        col=position.col;
        dir=position.dir;
        while((dir<8)&&(found==0))
        {
            next_row=row+movevert(dir);
            next_col=col+movehoriz(dir);
            if((next_row==exit_row)&&(next_col==exit_col))
            {
                mark[row][col]=1;
                found=1;
            }
            else if((maze[next_row][next_col]==0)&&(mark[next_row][next_col]==0))
            {
                mark[next_row][next_col]=1;
                position.row=row;
                position.col=col;
                position.dir=++dir;
                push(position);
                row=next_row;
                col=next_col;
                dir=0;
            }
            else
            {
                ++dir;
            }
        }
        if(found==0) mark[row][col]=0;
    }
    if(found==1)
    {
        mark[exit_row][exit_col]=1;
        for(x=1; x<rownum+1; x++)
        {
            for(y=1; y<colnum+1; y++)
            {
                if(mark[x][y]==1)
                {
                    SetColor(4,0);
                    cout<<maze[x][y];
                    SetColor();
                }
                else
                {
                    cout<<maze[x][y];
                }
            }
            cout<<endl;
        }

    }
    else
    {
        cout<<"The maze does not have a path"<<endl;
    }
}

int main()
{
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            maze[i][j]=1;
        }
    }

    ifstream fp ("input2-3.txt");
    if(!fp){
        cout<<"阿就讀不到檔案我有什麼辦法哀哀哀"<<endl;
    }


    fp>>rownum;
    fp>>colnum;
    exit_row=rownum;
    exit_col=colnum;
    for(i=1; i<rownum+1; i++)
    {
        for(j=1; j<colnum+1; j++)
        {
            fp>>maze[i][j];
        }
    }
    path();
    return 0;
}
