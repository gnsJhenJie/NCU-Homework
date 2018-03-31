//104502518 ¼B«aÁn
#include<iostream>
using namespace std;
int main () {
    int ID,Hcm,W; //declare variable : ID,Height(cm),Weight(kg)
    float Hm,BMI; //declare variable : Height(m),BMI

    cout<<"BMI = Weight/<Height^2>\n\n";
    cout<<"Please input your ID: ";
    cin>>ID; //input ID
    cout<<"Please input your weight: ";
    cin>>W; //input Weight
    cout<<"Please input your height <CM>: ";
    cin>>Hcm; //input Height(cm)
    Hm=Hcm/100.0; //Height(cm) convert to Height(m)
    BMI=W/(Hm*Hm); //calculate BMI
    cout<<"\nHi! "<<ID<<" Your BMI: "<<BMI;

    return 0;
}
