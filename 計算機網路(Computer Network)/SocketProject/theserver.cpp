#pragma comment(lib,"ws2_32.lib")
#include<winsock2.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<algorithm>

using namespace std;

SOCKET Connections[100];
int ConnectionCounter=0;
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

bool SendInt(int index,int _int){
    int RetnCheck=send(Connections[index],(char*)&_int,sizeof(int),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool GetInt(int index,int &_int){
    int RetnCheck=recv(Connections[index],(char*)&_int,sizeof(int),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool SendPacketType(int index,Packet _packettype){
    int RetnCheck=send(Connections[index],(char*)&_packettype,sizeof(Packet),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool GetPacketType(int index,Packet &_packettype){
    int RetnCheck=recv(Connections[index],(char*)&_packettype,sizeof(Packet),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool SendString(int index,string &_string){
    if(!SendPacketType(index,P_ChatMessage)){
        return false;
    }
    int bufferlength=_string.size();
    if(!SendInt(index,bufferlength)){
        return false;
    }
    int RetnCheck=send(Connections[index],_string.c_str(),bufferlength,NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool GetString(int index,string &_string){
    int bufferlength;
    if(!GetInt(index,bufferlength)){
        return false;
    }
    char *buffer=new char[bufferlength+1];
    buffer[bufferlength]='\0';
    int RetnCheck=recv(Connections[index],buffer,bufferlength,NULL);
    _string=buffer;
    delete[] buffer;
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    return true;
}

bool SendFile(int index,FILE *f){
    if(!SendPacketType(index,P_File)){
        return false;
    }
    int RetnCheck=send(Connections[index],(char*)&filenamelength,sizeof(int),NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    RetnCheck=send(Connections[index],(char*)&filename,filenamelength,NULL);
    if(RetnCheck==SOCKET_ERROR){
        return false;
    }
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    rewind(f);
    if (filesize == EOF)
        return false;
    if (!sendlong(Connections[index], filesize))
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
            if (!senddata(Connections[index], buffer, num))
                return false;
            filesize -= num;
        }
        while (filesize > 0);
    }
    return true;
}

bool GetFile(int index,FILE *f){
    long filesize;
    if (!readlong(Connections[index], &filesize))
        return false;
    if (filesize > 0)
    {
        char buffer[1024];
        do
        {
            int num = min(filesize, (long)sizeof(buffer));
            if (!readdata(Connections[index], buffer, num))
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
    return true;
}

bool ProcessPacket(int index,Packet packettyp){
    switch(packettyp){
    case P_ChatMessage:{
        string Message;
        if(!GetString(index,Message)){
            return false;
        }
        for(int i=0;i<ConnectionCounter;i++){
            if(i==index){
                continue;
            }
            if(!SendString(i,Message)){
                cout<<"Failed to send message form client ID: "<<index<<"to client ID: "<<i<<endl;
            }
        }
        cout<<"Processed chat message packet from user ID: "<<index<<endl;
        break;
    }
    case P_File:{
        int RetnCheck=recv(Connections[index],(char*)&filenamelength,sizeof(int),NULL);
        if(RetnCheck==SOCKET_ERROR){
            return false;
        }
        RetnCheck=recv(Connections[index],(char*)&filename,filenamelength,NULL);
        if(RetnCheck==SOCKET_ERROR){
            return false;
        }
        FILE *filehandle = fopen(filename, "wb");
        if (filehandle != NULL)
        {
            if(!GetFile(index,filehandle)){
                remove(filename);
                fclose(filehandle);
                return false;
            }
            fclose(filehandle);
        }
        filehandle = fopen(filename, "rb");
        if(filehandle!=NULL){
            for(int i=0;i<ConnectionCounter;i++){
                if(i==index){
                    continue;
                }
                if(!SendFile(i,filehandle)){
                    cout<<"Failed to send message form client ID: "<<index<<"to client ID: "<<i<<endl;
                }
            }
            cout<<"Processed file packet from user ID: "<<index<<endl;
            fclose(filehandle);
        }
        else{
            cout<<"no this file."<<endl;
            fclose(filehandle);
        }
        break;
    }
    default:
        cout<<"Unrecognized packet: "<<packettyp<<endl;
        break;
    }

    return true;
}

void ClientHandlerThread(int index){
    Packet packettype;
    while(true){
        if(!GetPacketType(index,packettype)){
            break;
        }

        if(!ProcessPacket(index,packettype)){
            break;
        }
    }
    cout<<"Lost connection to client ID: "<<index<<endl;
    closesocket(Connections[index]);
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
    cout<<"請輸入ip位址: ";
    cin>>ipip;
    addr.sin_addr.s_addr = inet_addr(ipip);
    addr.sin_port = htons(1234);
    addr.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET,SOCK_STREAM,NULL);
    bind(sListen,(SOCKADDR*)&addr,sizeof(addr));
    listen(sListen, SOMAXCONN);

    SOCKET newConnection;
    for(int i =0;i<100;i++){
        newConnection=accept(sListen,(SOCKADDR*)&addr,&addrlen);
        if(newConnection==0){
            cout<<"Failed to accept the client's connection."<<endl;
        }
        else{
            cout<<"Client Connected!"<<endl;
            Connections[i]=newConnection;
            ConnectionCounter++;
            CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)ClientHandlerThread,(LPVOID)(i),NULL,NULL);
            string RAMA="1.輸入文字訊息格式：[除了F:開頭以外任意輸入]+{ENTER}\n2.傳送檔案給其他所有client格式：[F:]+{ENTER}+[主檔名.副檔名]";
            SendString(i,RAMA);
        }
    }


    system("pause");
    return 0;
}
