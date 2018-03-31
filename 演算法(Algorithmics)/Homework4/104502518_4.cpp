#include<iostream>
#include<algorithm>
using namespace std;



int weight;

struct EV{
    int x;
    int y;
    int w;
};

bool compare(EV ll,EV rr){
    return ll.w<rr.w;
}

bool findd(int *dad,int x,int y){
    int i=x,j=y,t;
    while(dad[i]>-1){
        i=dad[i];
    }
    while(dad[j]>-1){
        j=dad[j];
    }
    if(i!=j){
        if(dad[i]<dad[j]){
            dad[i]+=dad[j];
            dad[j]=i;
            while(dad[y]>-1){
                t=y;
                y=dad[y];
                dad[t]=i;
            }
        }
        else{
            dad[j]+=dad[i];
            dad[i]=j;
            while(dad[x]>-1){
                t=x;
                x=dad[x];
                dad[t]=j;
            }
        }
    }

    return (i!=j);
}

void submain(int n,int m){
    EV all[m];
    int dad[n];
    for(int i=0;i<n;i++){
        dad[i]=-1;
    }
    for(int i=0;i<m;i++){
        cin>>all[i].x;
        cin>>all[i].y;
        cin>>all[i].w;
    }
    sort(all,all+m,compare);
    for(int i=0;i<m;i++){
        if(findd(dad,all[i].x,all[i].y)){
            weight+=all[i].w;
        }
    }
}

int main(){
    int m,n,first=0;
    cin>>n;
    cin>>m;
    while(1){
        weight=0;
        if(n==0&&m==0){
            break;
        }

        submain(n,m);

        if(first==0){
            first=1;
        }
        else{
            cout<<endl;
        }
        cout<<weight;

        cin>>n;
        cin>>m;
    }

}
