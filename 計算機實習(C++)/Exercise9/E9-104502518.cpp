#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string bla;
    int n=1,result,f=0,b=0,i,j;
    cout<<"Input your Mathematic Forms\n";
    do{
       cout<<"Input "<<n<<" Mathematic Forms: ";
       cin>>bla;        //input string to calculate
       if(bla=="END"){
        return 0;
       }
       for(i=0;i<bla.length();i++){     //start calculation
            if(bla[i]=='+'){        //form of +
                for(j=0;j<i;j++){
                    f=f*10+(bla[j]-48);
                }
                for(j=i+1;j<bla.length();j++){
                    b=b*10+(bla[j]-48);
                }
                result=f+b;
                break;
            }
            else if(bla[i]=='-'){       //form of -
                for(j=0;j<i;j++){
                    f=f*10+(bla[j]-48);
                }
                for(j=i+1;j<bla.length();j++){
                    b=b*10+(bla[j]-48);
                }
                result=f-b;
                break;
            }
            else if(bla[i]=='*'){       //form of *
                for(j=0;j<i;j++){
                    f=f*10+(bla[j]-48);
                }
                for(j=i+1;j<bla.length();j++){
                    b=b*10+(bla[j]-48);
                }
                result=f*b;
                break;
            }
            else if(bla[i]=='/'){       //form of /
                for(j=0;j<i;j++){
                    f=f*10+(bla[j]-48);
                }
                for(j=i+1;j<bla.length();j++){
                    b=b*10+(bla[j]-48);
                }
                if(b==0){
                    break;
                }
                result=f/b;
                break;
            }
       }
       if(bla[i]=='/'&&b==0){       //debug
            cout<<"Wrong input. Please input correct Mathematic Forms\n\n";
            f=b=result=0;
            continue;
        }
       cout<<"Sol "<<n<<") "<<bla<<" = "<<result<<endl<<endl;
       n++;
       f=b=result=0;
    }while(bla!="END");     //debug
    return 0;
}
