#include<cstdlib>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#define isfull(temp) (!(temp))
using namespace std;
typedef struct poly_node *poly_pointer;
typedef struct poly_node
{
    int coef;
    int exp;
    poly_pointer link;
};
poly_pointer a,b,d;


void attach(float coefficient,int exponent,poly_pointer *ptr)
{
    poly_pointer temp;
    temp=(poly_pointer)malloc(sizeof(poly_node));
    if(isfull(temp))
    {
        cout<<"碞⊿丁иΤぐ或快猭拈"<<endl;
        exit(1);
    }
    temp->coef=coefficient;
    temp->exp=exponent;
    (*ptr)->link=temp;
    *ptr=temp;
}

poly_pointer padd(poly_pointer a, poly_pointer b)
{
    poly_pointer frontt,rear,temp;
    int sum;
    temp=(poly_pointer)malloc(sizeof(poly_node));
    frontt=(poly_pointer)malloc(sizeof(poly_node));
    rear=(poly_pointer)malloc(sizeof(poly_node));
    if(isfull(rear))
    {
        cout<<"碞⊿丁иΤぐ或快猭拈"<<endl;
        exit(1);
    }
    frontt=rear;
    while(a&&b)
    {
        if((a->exp)<(b->exp))
        {
            attach(b->coef,b->exp,&rear);
            b=b->link;
        }
        else if((a->exp)==(b->exp))
        {
            sum=(a->coef)+(b->coef);
            if(sum!=0)
            {
                attach(sum,a->exp,&rear);
            }
            a=a->link;
            b=b->link;
        }
        else if((a->exp)>(b->exp))
        {
            attach(a->coef,a->exp,&rear);
            a=a->link;
        }
    }
    for(; a; a=a->link)
    {
        attach(a->coef,a->exp,&rear);
    }
    for(; b; b=b->link)
    {
        attach(b->coef,b->exp,&rear);
    }
    rear->link=NULL;
    temp=frontt;
    frontt=frontt->link;
    free(temp);
    return frontt;
}

int main()
{
    a=(poly_pointer)malloc(sizeof(poly_node));
    b=(poly_pointer)malloc(sizeof(poly_node));
    d=(poly_pointer)malloc(sizeof(poly_node));
    stringstream ss;
    d=a;
    ifstream inputfile;
    inputfile.open("input3.txt",ifstream::in);
    string line;
    int coefficient,exponent,i;
    getline(inputfile,line);
    while(line.length()>1)
    {
        //cout<<line<<endl;
        for(i=0; i<line.length(); i++)
        {
            if(line[i]==' ')
            {
                ss<<line.substr(0,i);
                ss>>coefficient;
                ss.str("");
                ss.clear();
                ss<<line.substr(i+1,line.length()-i-1);
                ss>>exponent;
                ss.str("");
                ss.clear();
                attach((float)coefficient,exponent,&a);
            }
        }
        getline(inputfile,line);
    }
    a->link=NULL;
    a=d;
    d=b;
    getline(inputfile,line);
    while(line.length()>1)
    {
        //cout<<line<<endl;
        for(i=0; i<line.length(); i++)
        {
            if(line[i]==' ')
            {
                ss<<line.substr(0,i);
                ss>>coefficient;
                ss.str("");
                ss.clear();
                ss<<line.substr(i+1,line.length()-i-1);
                ss>>exponent;
                ss.str("");
                ss.clear();
                attach((float)coefficient,exponent,&b);
            }
        }
        getline(inputfile,line);
    }
     b->link=NULL;
     b=d;
     a=a->link;
     b=b->link;


     d=padd(a,b);

     while(d){
         cout<<d->coef<<" "<<d->exp<<endl;
         d=d->link;
     }

    return 0;
}
