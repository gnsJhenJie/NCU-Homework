#pragma comment(lib,"ws2_32.lib")
#include<winsock2.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<algorithm>
using namespace std;

SOCKET Connection;
char filename[50];
int filenamelength;

enum Packet{
    P_ChatMessage,
    P_File
};

bool senddata(SOCKET sock, void *buf, int buflen)
{
    char *pbuf = (char *) buf;

    while (buflen > 0)
    {
        int num = send(sock, pbuf, buflen, 0);
        if (num == SOCKET_ERROR)
        {
            if (WSAGetLastError() == WSAEWOULDBLOCK)
            {
                continue;
            }
            return false;
        }

        pbuf += num;
        buflen -= num;
    }

    return true;
}

bool sendlong(SOCKET sock, long value)
{
    value = htonl(value);
    return senddata(sock, &value, sizeof(value));
}

bool readdata(SOCKET sock, void *buf, int buflen)
{
    char *pbuf = (char *) buf;

    while (buflen > 0)
    {
        int num = recv(sock, pbuf, buflen, 0);
        if (num == SOCKET_ERROR)
        {
            if (WSAGetLastError() == WSAEWOULDBLOCK)
            {
                continue;
            }
            return false;
        }
        else if (num == 0)
            return false;

        pbuf += num;
        buflen -= num;
    }

    return true;
}

bool readlong(SOCKET sock, long *value)
{
    if (!readdata(sock, value, sizeof(value)))
        return false;
    *value = ntohl(*value);
    return true;
}

bool SendInt(int _int){
    int RetnCheck=send(Connection,(char*)&_int,sizeof(int),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool GetInt(int &_int){
    int RetnCheck=recv(Connection,(char*)&_int,sizeof(int),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool SendPacketType(Packet _packettype){
    int RetnCheck=send(Connection,(char*)&_packettype,sizeof(Packet),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool GetPacketType(Packet &_packettype){
    int RetnCheck=recv(Connection,(char*)&_packettype,sizeof(Packet),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool SendString(string &_string){
    if(!SendPacketType(P_ChatMessage)){
        return false;
    }
    int bufferlength=_string.size();
    if(!SendInt(bufferlength)){
        return false;
    }
    int RetnCheck=send(Connection,_string.c_str(),bufferlength,NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool GetString(string &_string){
    int bufferlength;
    if(!GetInt(bufferlength)){
        return false;
    }
    char *buffer=new char[bufferlength+1];
    buffer[bufferlength]='\0';
    int RetnCheck=recv(Connection,buffer,bufferlength,NULL);
    _string=buffer;
    delete[] buffer;
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool SendFile(FILE *f){
    if(!SendPacketType(P_File)){
        return false;
    }
    int RetnCheck=send(Connection,(char*)&filenamelength,sizeof(int),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    RetnCheck=send(Connection,(char*)&filename,filenamelength,NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    rewind(f);
    if (filesize == EOF)
        return false;
    if (!sendlong(Connection, filesize))
        return false;
    if (filesize > 0)
    {
        char buffer[1024];
        do
        {
            size_t num = min(filesize, (long)sizeof(buffer));
            num = fread(buffer, 1, num, f);
            if (num < 1)
                return false;
            if (!senddata(Connection, buffer, num))
                return false;
            filesize -= num;
        }
        while (filesize > 0);
    }
    return true;
}

bool GetFile(FILE *f){
    long filesize;
    if (!readlong(Connection, &filesize))
        return false;
    if (filesize > 0)
    {
        char buffer[1024];
        do
        {
            int num = min(filesize, (long)sizeof(buffer));
            if (!readdata(Connection, buffer, num))
                return false;
            int offset = 0;
            do
            {
                size_t written = fwrite(&buffer[offset], 1, num-offset, f);
                if (written < 1)
                    return false;
                offset += written;
            }
            while (offset < num);
            filesize -= num;
        }
        while (filesize > 0);
    }
    cout<<"Get the File: "<<filename<<endl;
    return true;
}


bool ProcessPacket(Packet packettype){
    switch(packettype){
    case P_ChatMessage:{
        string Message;
        if(!GetString(Message)){
            return false;
        }
        cout<<Message<<endl;
        break;
    }
    case P_File:{
        int RetnCheck=recv(Connection,(char*)&filenamelength,sizeof(int),NULL);
        if(RetnCheck==SOCKET_ERROR){
            return false;
        }
        RetnCheck=recv(Connection,(char*)&filename,filenamelength,NULL);
        if(RetnCheck==SOCKET_ERROR){
            return false;
        }
        FILE *filehandle = fopen(filename, "wb");
        if (filehandle != NULL)
        {
            if(!GetFile(filehandle)){
                remove(filename);
                fclose(filehandle);
                return false;
            }
            fclose(filehandle);
        }
        fclose(filehandle);
        break;
    }
    default:
        cout<<"Unrecognized packet: "<<packettype<<endl;
        break;
    }
    return true;
}

void ClientThread(){
    Packet packettype;
    while(true){
        if(!GetPacketType(packettype)){
            break;
        }

        if(!ProcessPacket(packettype)){
            break;
        }
    }
    cout<<"Lost connection to the server."<<endl;
    closesocket(Connection);
}

int main(){

    WSAData wsaData;
    WORD DllVersion=MAKEWORD(2,1);
    if(WSAStartup(DllVersion,&wsaData)!=0){
        MessageBoxA(NULL,"Winsock startup failed","Error",MB_OK | MB_ICONERROR);
        exit(1);
    }

    SOCKADDR_IN addr;
    int addrlen = sizeof(addr);
    char ipip[20];
    cout<<"請輸入server的ip位址: ";
    cin>>ipip;
    addr.sin_addr.s_addr = inet_addr(ipip);
    addr.sin_port = htons(1234);
    addr.sin_family = AF_INET;

    Connection = socket(AF_INET,SOCK_STREAM,NULL);
    if(connect(Connection,(SOCKADDR*)&addr,sizeof(addr))!=0){
        MessageBoxA(NULL,"failed to Connect","Error",MB_OK | MB_ICONERROR);
        return 0;
    }
    cout<<"Connected!"<<endl;
    CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ClientThread,NULL,NULL,NULL);

    string userinput;

    FILE *filehandle;
    while(true){
        getline(cin,userinput);
        if(userinput[0]=='F'&&userinput[1]==':'){
            //filename=userinput.substr(2,userinput.length()-2).c_str();
            cin>>filename;
            for(int i=0;filename[i]!='\0';i++){
                filenamelength=i+2;
            }
            filehandle = fopen(filename, "rb");
            if(filehandle!=NULL){
                if(!SendFile(filehandle)){
                    fclose(filehandle);
                    break;
                }
                fclose(filehandle);
            }
            else{
                cout<<*filename<<endl;
                cout<<"no this file."<<endl;
                fclose(filehandle);
            }

        }
        else{
            if(!SendString(userinput)){
                break;
            }
        }


        Sleep(10);
    }

    system("pause");
    return 0;
}
