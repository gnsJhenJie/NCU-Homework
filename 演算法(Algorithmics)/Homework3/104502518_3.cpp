#include<iostream>
#include<algorithm>
using namespace std;

int c,alltime;

struct task{
    int t;
    int d;
};

bool tcompare(task ll,task rr){
    return ll.d<rr.d;
}

void downheap(int k,int *a){
    int j;
    int v;
    v=a[k];
    while(k<=c/2){
        j=k+k;
        if(j<c&&a[j]<a[j+1]){
            j++;
        }
        if(v>=a[j]){
            break;
        }
        a[k]=a[j];
        k=j;
    }
    a[k]=v;
}

void upheap(int j,int *a){
    int v;
    v=a[j];
    a[0]=40000;
    while(a[j/2]<v){
        a[j]=a[j/2];
        j=j/2;
    }
    a[j]=v;
}

void insertt(int v,int *a){
    a[++c]=v;
    upheap(c,a);
}

void removee(int *a){
    alltime-=a[1];
    a[1]=a[c--];
    downheap(1,a);
}

void submain(int n){
    int a[n+2];
    task tt[n];
    for(int i=0;i<n;i++){
        cin>>tt[i].t;
        cin>>tt[i].d;
        a[i]=0;
    }
    sort(tt,tt+n,tcompare);
    for(int i=0;i<n;i++){
        insertt(tt[i].t,a);
        alltime+=tt[i].t;
        if(alltime>tt[i].d){
            removee(a);
        }
    }
    cout<<c;
}

int main(){
    int k,n;
    cin>>k;
    for(int i=0;i<k;i++){
        c=alltime=0;
        cin>>n;
        submain(n);
        if(i!=k-1){
            cout<<endl;
        }
    }
    return 0;
}
