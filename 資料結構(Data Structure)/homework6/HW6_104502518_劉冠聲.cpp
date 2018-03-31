#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;

int main(){
    ifstream input("input6.txt");
    int n,i,j,k;
    input>>n;
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            input>>a[i][j];
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if((a[i][k] + a[k][j]) < (a[i][j])){
                    a[i][j] = (a[i][k]) + (a[k][j]);
                }
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<left<<setw(8)<<a[i][j]<<" ";
        }
        cout<<endl;
    }








    return 0;
}
