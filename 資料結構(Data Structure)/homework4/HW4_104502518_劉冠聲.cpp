#include<cstdlib>
#include<iostream>
#include<cstring>
#include<iomanip>
#define isfull(x) (!(x))
using namespace std;

typedef struct node *nodepointer;
typedef struct node
{
    int data;
    nodepointer link;
};
int main()
{
    int n,i,j;
    nodepointer x,y,top;
    cout<<"Enter n: ";
    cin>>n;
    nodepointer seq[n];
    int out[n];

    for(i=0; i<n; i++)
    {
        out[i]=0;
        seq[i]=NULL;
    }

    cout<<"Enter a pair of numbers (-1 -1 to quit): ";
    cin>>i>>j;
    while(i>=0)
    {
        x=(nodepointer)malloc(sizeof(node));
        if(isfull(x))
        {
            cout<<"就沒空間阿!重灌了阿!"<<endl;
            exit(1);
        }
        x->data=j;
        x->link=seq[i];
        seq[i]=x;
        x=(nodepointer)malloc(sizeof(node));
        if(isfull(x))
        {
            cout<<"就沒空間阿!重灌了阿!"<<endl;
            exit(1);
        }
        x->data=i;
        x->link=seq[j];
        seq[j]=x;
        cout<<"Enter a pair of numbers (-1 -1 to quit): ";
        cin>>i>>j;
    }

    for(i=0; i<n; i++)
    {
        if(out[i]==0)
        {
            cout<<endl<<"New class: "<<setw(5)<<i;
            out[i]=1;
            x=seq[i];
            top=NULL;
            for(;;)
            {
                while(x)
                {
                    j=x->data;
                    if(out[j]==0)
                    {
                        cout<<setw(5)<<j;
                        out[j]=1;
                        y=x->link;
                        x->link=top;
                        top=x;
                        x=y;
                    }
                    else
                    {
                        x=x->link;
                    }
                }
                if(!top)
                {
                    break;
                }
                x=seq[top->data];
                top=top->link;
            }
        }
    }
    return 0;
}
