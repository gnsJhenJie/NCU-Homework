#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>       //include header
using namespace std;
struct link{        //declare struct
    int n;      //number in link
    link *next;     //link address
}a[10];     //10structs
int main(){
    link *ptr1,*ptr2;       //declare 2 variable of link address
    int i,cut;
    srand(time(NULL));      //for rand
    for(i=0;i<10;i++){
        a[i].n=rand()%99+1;
        cout<<setw(4)<<a[i].n;      //give number to every link
        if(i<9){
            a[i].next=&a[i+1];
        }
        else{
            a[i].next=NULL;     //the last link point to NULL
        }
    }
    ptr1=&a[0];
    ptr2=ptr1->next;
    cout<<"\ncut: ";
    while(cin>>cut){        //start cut
        while(ptr1->next!=NULL){
            if(ptr2->n==cut){
                if(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                    ptr1->next=ptr2;
                }
                else{
                    ptr1->next=NULL;
                }
            }
            else{
                cout<<setw(4)<<ptr1->n;     //cout result
                ptr2=ptr2->next;
                ptr1=ptr1->next;
            }
        }
        cout<<setw(4)<<ptr1->n<<endl;
        ptr1=&a[0];
        ptr2=ptr1->next;
        cout<<"cut: ";
    }
    return 0;
}
