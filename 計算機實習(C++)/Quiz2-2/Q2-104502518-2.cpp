#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
    string s;
    int n1=0,n2=0;      //declare variable
    int i=0,j;
    ifstream fin("input.txt");      //open txt
    while(fin>>s){      //get the form from txt
        while(1){
            if(s[i]=='+'){      //judge sign
                break;
            }
            else if(s[i]=='-'){
                break;
            }
            else if(s[i]=='*'){
                break;
            }
            else if(s[i]=='/'){
                break;
            }
            i++;
        }
        for(j=0;j<i;j++){       //get number 1
            n1=n1*10+(s[j]-48);
        }
        for(j=i+1;j<s.length();j++){        //get number 2
            n2=n2*10+(s[j]-48);
        }
        if(s[i]=='+'){      //output result
            cout<<n1<<s[i]<<n2<<" = "<<n1+n2;
        }
        else if(s[i]=='-'){
            cout<<n1<<s[i]<<n2<<" = "<<n1-n2;
        }
        else if(s[i]=='*'){
            cout<<n1<<s[i]<<n2<<" = "<<n1*n2;
        }
        else if(s[i]=='/'){
            cout<<n1<<s[i]<<n2<<" = "<<n1/n2;
        }
        i=n1=n2=0;
        cout<<endl;
    }
    fin.close();        //close txt
    return 0;
}
