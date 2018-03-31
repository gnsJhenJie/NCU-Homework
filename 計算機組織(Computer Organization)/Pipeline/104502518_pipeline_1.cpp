#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<cstring>
using namespace std;

int strtodec(string source){

    int target=0,x;
    for(x=0;x<source.length();x++){
        target=target*2;
        if(source[x]=='1'){
            target++;
        }
    }

    return target;
}

int main(){
    string a[20];
    string opcode[20],func[20],whatrs[20],whatrt[20],whatrd[20],immediate[20];//opcode&func
    int nowregister[10]={0};
    ifstream fin("General.txt");        //No.1 input
    ofstream fout("genResult.txt");     //No.1 output
    string line,instruction,control9="000000000",control5="00000",control2="00",tempstring;
    string inszero="00000000000000000000000000000000";
    string rtype="000000",lw="100011",sw="101011",addi="001000",andi="001100",bne="000101";//opcode
    string Add="100000",Sub="100010",And="100100",Ore="100101",Slt="101010";//function
    int n=0,i,j,tempint[10]={0,0,0,0,0,0,0,0,0,0},last,lastlast,x,y;
    int t[10]={0,9,8,7,1,2,3,4,5,6},m0=5,m4=9,m8=4,mc=8,m10=7;
    int pc=4,rd1=0,rd2=0,sign=0,rs=0,rt=0,rd=0,aluoutex=0,writedata=0,rtrd=0,readdata=0,aluoutmem=0;

    while(getline(fin,line)){
        a[n++]=line;
    }
    for(i=n;i<20;i++){
        a[i]=inszero;
    }
    /*55555555555555555555555555*/
    //read instruction
    /*55555555555555555555555555*/

    for(i=0;i<n+4;i++){             //print out result
        instruction=a[i];           //fetch for IF/ID
        opcode[i]=instruction.substr(0,6);
        func[i]=instruction.substr(26,6);
        whatrs[i]=instruction.substr(6,5);
        whatrt[i]=instruction.substr(11,5);
        whatrd[i]=instruction.substr(16,5);
        immediate[i]=instruction.substr(16,16);
        if(i>=4){                   //WB for Registers
            if(a[i-4]==inszero){

            }
            else{
                if(opcode[i-4]==rtype){
                    t[strtodec(whatrd[i-4])]=aluoutmem;
                    tempint[strtodec(whatrd[i-4])]=0;
                }
                else if(opcode[i-4]==lw){
                    t[strtodec(whatrt[i-4])]=readdata;
                    tempint[strtodec(whatrt[i-4])]=0;
                }
                else if(opcode[i-4]==addi){
                    t[strtodec(whatrt[i-4])]=aluoutmem;
                    tempint[strtodec(whatrt[i-4])]=0;
                }
                else if(opcode[i-4]==andi){
                    t[strtodec(whatrt[i-4])]=aluoutmem;
                    tempint[strtodec(whatrt[i-4])]=0;
                }
                else if(opcode[i-4]==bne){

                }
                else if(opcode[i-4]==sw){

                }
            }
        }
        if(i>=3){                   //MEM for MEM/WB & Data memory
            if(a[i-3]==inszero){
                readdata=aluoutmem=0;
                control2="00";
            }
            else{
                control2=control5.substr(3,2);
                aluoutmem=aluoutex;
                if(opcode[i-3]==lw){
                    if(aluoutmem==0){           //read memory
                        readdata=m0;
                    }
                    else if(aluoutmem==4){
                        readdata=m4;
                    }
                    else if(aluoutmem==8){
                        readdata=m8;
                    }
                    else if(aluoutmem==12){
                        readdata=mc;
                    }
                    else if(aluoutmem==16){
                        readdata=m10;
                    }
                }
                else if(opcode[i-3]==sw){       //write to memory
                    readdata=0;
                    if(aluoutmem==0){
                        m0=writedata;
                    }
                    else if(aluoutmem==4){
                        m4=writedata;
                    }
                    else if(aluoutmem==8){
                        m8=writedata;
                    }
                    else if(aluoutmem==12){
                        mc=writedata;
                    }
                    else if(aluoutmem==16){
                        m10=writedata;
                    }
                }
                else{
                    readdata=0;
                }
            }
        }
        if(i>=2){                   //execute for EX/MEM
            if(a[i-2]==inszero){
                aluoutex=writedata=rtrd=0;
                control5="00000";
            }
            else{
                writedata=t[strtodec(whatrt[i-2])];
                control5=control9.substr(4,5);
                if(opcode[i-2]==rtype){                         //if it is rtype
                    if(tempint[strtodec(whatrs[i-2])]==1){      //if it is rs datahazard and use latch
                        if(opcode[i-3]==rtype){
                            if(whatrs[i-2]==whatrd[i-3]){
                                x=aluoutex;
                            }
                        }
                        else{
                            if(whatrs[i-2]==whatrt[i-3]){
                                x=aluoutex;
                            }
                        }
                        if(opcode[i-4]==rtype){
                            if(whatrs[i-2]==whatrd[i-4]){
                                x=aluoutmem;
                            }
                        }
                        else{
                            if(whatrs[i-2]==whatrt[i-4]){
                                x=aluoutmem;
                            }
                        }

                    }
                    else{
                        x=t[strtodec(whatrs[i-2])];
                    }
                    if(tempint[strtodec(whatrt[i-2])]==1){      //if it is rt datahazard and use latch
                        if(opcode[i-3]==rtype){
                            if(whatrt[i-2]==whatrd[i-3]){
                                y=aluoutex;
                            }
                        }
                        else{
                            if(whatrt[i-2]==whatrt[i-3]){
                                y=aluoutex;
                            }
                        }
                        if(opcode[i-4]==rtype){
                            if(whatrt[i-2]==whatrd[i-4]){
                                y=aluoutmem;
                            }
                        }
                        else{
                            if(whatrt[i-2]==whatrt[i-4]){
                                y=aluoutmem;
                            }
                        }

                    }
                    else{
                        y=t[strtodec(whatrt[i-2])];
                    }
                    rtrd=strtodec(whatrd[i-2]);
                    if(func[i-2]==Add){             //if it is add
                        aluoutex=x+y;
                    }
                    else if(func[i-2]==Sub){        //if it is sub
                        aluoutex=x-y;
                    }
                    else if(func[i-2]==And){        //if it is and
                        aluoutex=x&y;
                    }
                    else if(func[i-2]==Ore){            //if it is or
                        aluoutex=x|y;
                    }
                    else if(func[i-2]==Slt){            //if it is slt
                        if(strtodec(whatrs[i-2])<strtodec(whatrt[i-2])){
                            aluoutex=1;
                        }
                        else{
                            aluoutex=0;
                        }
                    }
                }
                else{
                    rtrd=strtodec(whatrt[i-2]);
                    if(tempint[strtodec(whatrs[i-2])]==1){      //if it is rs datahazard and use latch
                        if(opcode[i-3]==rtype){
                            if(whatrs[i-2]==whatrd[i-3]){
                                x=aluoutex;
                            }
                        }
                        else{
                            if(whatrs[i-2]==whatrt[i-3]){
                                x=aluoutex;
                            }
                        }
                        if(opcode[i-4]==rtype){
                            if(whatrs[i-2]==whatrd[i-4]){
                                x=aluoutmem;
                            }
                        }
                        else{
                            if(whatrs[i-2]==whatrt[i-4]){
                                x=aluoutmem;
                            }
                        }
                    }
                    else{
                        x=t[strtodec(whatrs[i-2])];
                    }
                    if(opcode[i-2]==lw){                        //if it is lw
                        aluoutex=x+strtodec(immediate[i-2]);
                    }
                    else if(opcode[i-2]==sw){                   //if it is sw
                        aluoutex=x+strtodec(immediate[i-2]);

                    }
                    else if(opcode[i-2]==andi){                 //if it is andi
                        aluoutex=x&strtodec(immediate[i-2]);
                    }
                    else if(opcode[i-2]==addi){                 //if it is addi
                        aluoutex=x+strtodec(immediate[i-2]);
                    }
                    else if(opcode[i-2]==bne){

                    }
                }
            }

        }
        if(i>=1){                   //decoder for ID/EX
            if(a[i-1]==inszero){
                rd1=rd2=sign=rs=rt=rd=0;
                control9="000000000";
            }
            else{
                rs=strtodec(whatrs[i-1]);
                rt=strtodec(whatrt[i-1]);
                sign=strtodec(immediate[i-1]);
                rd1=t[rs];
                rd2=t[rt];

                if(opcode[i-1]==rtype){     //judge if the R type
                    rd=strtodec(whatrd[i-1]);
                    tempint[rd]=1;
                    control9="110000010";
                }
                else{
                    rd=0;
                    tempint[rt]=1;
                    if(opcode[i-1]==lw){                //if it is lw
                        control9="000101011";
                    }
                    else if(opcode[i-1]==sw){           //if it is sw
                        control9="000100100";
                    }
                    else if(opcode[i-1]==bne){          //if it is bne
                        control9="001010000";
                    }
                    else if(opcode[i-1]==addi){         //if it is addi
                        control9="000100010";
                    }
                    else if(opcode[i-1]==andi){         //if it is andi
                        control9="011100010";
                    }
                }
            }
        }
        last=aluoutex;
        lastlast=aluoutmem;
        //output to file
        fout<<"CC "<<i+1<<":"<<endl<<endl;
        fout<<"Registers:"<<endl;
        fout<<"$0: "<<t[0]<<endl<<"$1: "<<t[1]<<endl<<"$2: "<<t[2]<<endl<<"$3: "<<t[3]<<endl<<"$4: "<<t[4]<<endl;
        fout<<"$5: "<<t[5]<<endl<<"$6: "<<t[6]<<endl<<"$7: "<<t[7]<<endl<<"$8: "<<t[8]<<endl<<"$9: "<<t[9]<<endl<<endl;
        fout<<"Data memory:"<<endl<<"0x00: "<<m0<<endl<<"0x04: "<<m4<<endl<<"0x08: "<<m8<<endl<<"0x0C: "<<mc<<endl<<"0x10: "<<m10<<endl<<endl;
        fout<<"IF/ID :"<<endl<<"PC\t\t"<<pc<<endl<<"Instruction\t"<<instruction<<endl<<endl;
        fout<<"ID/EX :"<<endl<<"ReadData1\t"<<rd1<<endl<<"ReaData2\t"<<rd2<<endl<<"sign_ext\t"<<sign<<endl<<"Rs\t\t"<<rs<<endl;
        fout<<"Rt\t\t"<<rt<<endl<<"Rd\t\t"<<rd<<endl<<"Control signals\t"<<control9<<endl<<endl;
        fout<<"EX/MEM :"<<endl<<"ALUout\t\t"<<aluoutex<<endl<<"WriteData\t"<<writedata<<endl<<"Rt/Rd\t\t"<<rtrd<<endl<<"Control signals\t"<<control5<<endl<<endl;
        fout<<"MEM/WB :"<<endl<<"ReadData\t"<<readdata<<endl<<"ALUout\t\t"<<aluoutmem<<endl<<"Control signals\t"<<control2<<endl;
        fout<<"=================================================================";
        pc+=4;
        if(i!=n+3){
            fout<<endl;
        }
    }

    return 0;
}
