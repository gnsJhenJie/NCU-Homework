#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<windows.h>
#include<cstring>
#include<ctime>
#include<sstream>
using namespace std;
int updateTime = 0;
int readTime = 0;
int writerNumber = 1;
int readerNumber = 1;
time_t initTimer;
int data = 0;
int readerNow = 0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;    //lock of thread


string I2S(int n){      //int to string
    stringstream ss;
    ss<<n;
    return ss.str();
}

void* childReader(void *nope){      //reader thread
    srand(time(NULL)+readerNumber);     //seed of rand
    string number = I2S(readerNumber++);        //get the number
    string s = "\t [ Reader #"+number+" ] : ";         //make it's string
    string first = s + "enters the critical section \n";
    string second,second2;
    string third = s + "exits the critical section \n";
    int randNumber;
    time_t timer;
    randNumber=rand()%5+1;
    Sleep(randNumber*1000);


    while(1){
        timer=time(NULL);
        if(timer-initTimer>=120){       //time's out
            break;
        }

        pthread_mutex_lock(&mutex1);
        pthread_mutex_unlock(&mutex1);

        readerNow++;

        cout<<first;



        second = s + "reads database : " + I2S(data) + "\n";




        cout<<second;
        randNumber=rand()%3+2;
        second2 = s + "sleep " + I2S(randNumber) + " seconds\n";
        cout<<second2;
        readTime++;

        timer=time(NULL);
        while(time(NULL)-timer<randNumber){}

        cout<<third;

        readerNow--;
    }


    pthread_exit(NULL);     //close this thread
}

void* childWriter(void *nope){      //writer thread
    srand(time(NULL)+writerNumber);     //seed of rand
    string number = I2S(writerNumber++);        //get the number
    string s="[ Writer #"+number+" ] : ";         //make it's string
    string first = s + "enters the critical section \n";
    string second,second2;
    string third = s + "exits the critical section \n";
    int randNumber;
    time_t timer;
    randNumber=rand()%5+1;
    Sleep(randNumber*1000);


    while(1){
        timer=time(NULL);
        if(timer-initTimer>=120){       //time's out
            break;
        }

        pthread_mutex_lock(&mutex1);        //lock
        while(readerNow>0){}

        cout<<first;
        data = rand()%50+1;
        second = s + "updates database : " + I2S(data) + "\n";
        cout<<second;
        randNumber=rand()%6+5;
        second2 = s + "sleep " + I2S(randNumber) + " seconds\n";
        cout<<second2;
        updateTime++;

        timer=time(NULL);
        while(time(NULL)-timer<randNumber){}

        cout<<third;

        pthread_mutex_unlock(&mutex1);      //unlock

    }


    pthread_exit(NULL);     //close this thread
}

int main(){
    int m,n;

    cout<<"Please input writer number m : ";
    cin>>m;
    cout<<"Please input reader number n : ";
    cin>>n;
    initTimer = time(NULL);

    pthread_t writer[m];        //declare thread variable of writer
    pthread_t reader[n];        //declare thread variable of reader

    for(int i=0;i<m;i++){       //create thread of writer
        pthread_create(&writer[i],NULL,childWriter,(void *)NULL);
    }
    for(int i=0;i<n;i++){       //create thread of reader
        pthread_create(&reader[i],NULL,childReader,(void *)NULL);
    }

    Sleep(120000);      //time limit
    cout<<endl;
    pthread_mutex_lock(&mutex1);
    while(readerNow>0){}
    cout<<"Total updates : "<<updateTime<<endl;
    cout<<"Total readings : "<<readTime<<endl;
    pthread_mutex_unlock(&mutex1);

    for(int i=0;i<m;i++){       //wait all writer thread end
        pthread_join(writer[i],NULL);
    }
    for(int i=0;i<n;i++){       //wait all reader thread end
        pthread_join(reader[i],NULL);
    }
    system("pause");
    return 0;
}
