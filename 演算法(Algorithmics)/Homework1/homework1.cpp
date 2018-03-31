#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

int Threshold=28;       //�]�wThreshold���ȡA�ثe���լ�27~29���ɭԡA40000���H�����ꥭ���Ҫ᪺�ɶ��̵u�A����28�@��A�S����K�p�⤣�n�N��

void insertionSortForX(int *data,int *dataY,int *dataN,int *dataC,int length){      //��X��Insertion Sort
    int i,j,n,nY,nN,nC;
    for(i=1;i<length;i++){
        n=data[i];
        nY=dataY[i];
        nN=dataN[i];
        nC=dataC[i];
        for(j=i-1;j>=0&&data[j]>n;j--){
            data[j+1]=data[j];
            dataY[j+1]=dataY[j];
            dataN[j+1]=dataN[j];
            dataC[j+1]=dataC[j];
        }
        data[j+1]=n;
        dataY[j+1]=nY;
        dataN[j+1]=nN;
        dataC[j+1]=nC;
    }
}

void insertionSortForN(int *data,int *dataC,int length){        //�隸�Ǫ�Insertion Sort
    int i,j,n,nC;
    for(i=1;i<length;i++){
        n=data[i];
        nC=dataC[i];
        for(j=i-1;j>=0&&data[j]>n;j--){
            data[j+1]=data[j];
            dataC[j+1]=dataC[j];
        }
        data[j+1]=n;
        dataC[j+1]=nC;
    }
}
//��X�Ȫ�Merge�X��
void mergeForX(int *sortedData,int *sortedDataY,int *sortedDataN,int *sortedDataC,int *left,int *right,int *leftY,int *rightY,int *leftN,int *rightN,int *leftC,int *rightC,int leftl,int rightl){
    int leftIndex=0,rightIndex=0;
    for(int i=0;i<leftl+rightl;i++){
        if(leftIndex==leftl){
            sortedDataY[i]=rightY[rightIndex];
            sortedDataN[i]=rightN[rightIndex];
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
        else if(rightIndex==rightl){
            sortedDataY[i]=leftY[leftIndex];
            sortedDataN[i]=leftN[leftIndex];
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else if(left[leftIndex]<right[rightIndex]){
            sortedDataY[i]=leftY[leftIndex];
            sortedDataN[i]=leftN[leftIndex];
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else if(left[leftIndex]==right[rightIndex]){
            if(leftY[leftIndex]<rightY[rightIndex]){
                sortedDataY[i]=leftY[leftIndex];
                sortedDataN[i]=leftN[leftIndex];
                sortedDataC[i]=leftC[leftIndex];
                sortedData[i]=left[leftIndex++];
            }
            else{
                sortedDataY[i]=rightY[rightIndex];
                sortedDataN[i]=rightN[rightIndex];
                sortedDataC[i]=rightC[rightIndex];
                sortedData[i]=right[rightIndex++];
            }

        }
        else{
            sortedDataY[i]=rightY[rightIndex];
            sortedDataN[i]=rightN[rightIndex];
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
    }
}
//��X�Ȫ�Merge Sort
void mergeSortForX(int *data,int *dataY,int *dataN,int *dataC,int length){
    if(length>1){
        if(length<=Threshold){                      //�Y�Ƕi�Ӫ��}�C���פp��Threshold�A���insertion sort�i��Ƨ�
            insertionSortForX(data,dataY,dataN,dataC,length);
        }
        else{
            int middle=length/2;
            int left[middle],leftY[middle],leftN[middle],leftC[middle];
            int right[length-middle],rightY[length-middle],rightN[length-middle],rightC[length-middle];
            for(int i=0;i<middle;i++){
                left[i]=data[i];
                leftY[i]=dataY[i];
                leftN[i]=dataN[i];
                leftC[i]=dataC[i];
            }
            for(int j=middle;j<length;j++){
                right[j-middle]=data[j];
                rightY[j-middle]=dataY[j];
                rightN[j-middle]=dataN[j];
                rightC[j-middle]=dataC[j];
            }
            mergeSortForX(left,leftY,leftN,leftC,middle);
            mergeSortForX(right,rightY,rightN,rightC,length-middle);
            mergeForX(data,dataY,dataN,dataC,left,right,leftY,rightY,leftN,rightN,leftC,rightC,middle,length-middle);
        }

    }
}
//��Y�Ȫ�Merge�X��
void mergeForY(int *sortedData,int *sortedDataN,int *sortedDataC,int *left,int *right,int *leftN,int *rightN,int *leftC,int *rightC,int leftl,int rightl){
    int leftIndex=0,rightIndex=0;
    for(int i=0;i<leftl+rightl;i++){
        if(leftIndex==leftl){
            rightC[rightIndex]+=leftIndex;      //�k��ֶi�h�A�p���rank��
            sortedDataN[i]=rightN[rightIndex];
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
        else if(rightIndex==rightl){
            sortedDataN[i]=leftN[leftIndex];
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else if(left[leftIndex]<right[rightIndex]){
            sortedDataN[i]=leftN[leftIndex];
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else if(left[leftIndex]==right[rightIndex]){
            sortedDataN[i]=leftN[leftIndex];
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else{
            rightC[rightIndex]+=leftIndex;      //�k��ֶi�h�A�p���rank��
            sortedDataN[i]=rightN[rightIndex];
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
    }
}
//��Y�Ȫ�Merge Sort
void mergeSortForY(int *data,int *dataN,int *dataC,int length){
    if(length>1){
        int middle=length/2;
        int left[middle],leftN[middle],leftC[middle];
        int right[length-middle],rightN[length-middle],rightC[length-middle];
        for(int i=0;i<middle;i++){
            left[i]=data[i];
            leftN[i]=dataN[i];
            leftC[i]=dataC[i];
        }
        for(int j=middle;j<length;j++){
            right[j-middle]=data[j];
            rightN[j-middle]=dataN[j];
            rightC[j-middle]=dataC[j];
        }
        mergeSortForY(left,leftN,leftC,middle);
        mergeSortForY(right,rightN,rightC,length-middle);
        mergeForY(data,dataN,dataC,left,right,leftN,rightN,leftC,rightC,middle,length-middle);
    }
}
//�隸�Ǫ�Merge�X��
void mergeForN(int *sortedData,int *sortedDataC,int *left,int *right,int *leftC,int *rightC,int leftl,int rightl){
    int leftIndex=0,rightIndex=0;
    for(int i=0;i<leftl+rightl;i++){
        if(leftIndex==leftl){
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
        else if(rightIndex==rightl){
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else if(left[leftIndex]<right[rightIndex]){
            sortedDataC[i]=leftC[leftIndex];
            sortedData[i]=left[leftIndex++];
        }
        else{
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
    }
}
//�隸�Ǫ�Merge Sort
void mergeSortForN(int *data,int *dataC,int length){
    if(length>1){
        if(length<=Threshold){                      //�Y�Ƕi�Ӫ��}�C���פp��Threshold�A���insertion sort�i��Ƨ�
            insertionSortForN(data,dataC,length);
        }
        else{
            int middle=length/2;
            int left[middle],leftC[middle];
            int right[length-middle],rightC[length-middle];
            for(int i=0;i<middle;i++){
                left[i]=data[i];
                leftC[i]=dataC[i];
            }
            for(int j=middle;j<length;j++){
                right[j-middle]=data[j];
                rightC[j-middle]=dataC[j];
            }
            mergeSortForN(left,leftC,middle);
            mergeSortForN(right,rightC,length-middle);
            mergeForN(data,dataC,left,right,leftC,rightC,middle,length-middle);
        }

    }
}



int main(){

    int n;
    clock_t start,finish;       //start=�}�l�ɶ� finish=�@�t�Cmerge sort&insertion sort ���槹�᪺�ɶ�
    double during;              //during=�}�l�ܵ����������ɶ�
    srand( (unsigned)time(NULL) );
    cin>>n;
    while(n!=0){
        for(int number[n],x[n],y[n],c[n]={0},i=0;i<n;i++){      //�̷ӿ�J��n�ȫŧin���ת� ����,x,y,rank �}�C
            number[i]=i;
            cin>>x[i];      //�p�ݤ�ʿ�J������աA�бN�o�����Ѯ����õ��ѱ��U��rand���
            cin>>y[i];      //
            //x[i]=rand()%10000;      //�]���Τj�q����A�H�������K�A�p�ݴ���Threshold�i�N�o�����Ѯ����õ��ѱ��W��cin���
            //y[i]=rand()%10000;
            start=clock();          //�D�n���{�����e�}�l
            if(i==n-1){
                mergeSortForX(x,y,number,c,n);      //����X�Ȱ��Ƨ�
                mergeSortForY(y,number,c,n);        //�b��Y�Ȱ��Ƨ�
                mergeSortForN(number,c,n);          //�U����w���U�۪�rank�ȡA�Φ��ǱƧǦ^�ӭ쥻��J������
                finish=clock();                     //�D�n���{�����e����
                during=(double)finish-start;        //�p��g�L�ɶ�
                cout<<endl<<"rank��: ";
                for(int j=0;j<n;j++){       //��X�̦��ǱƧǹL��rank�ȡA�p�ݴ���Threshold��ĳ�N��for���ѱ������ݪ�h�֮ɶ�
                    cout<<c[j]<<" ";
                }
            }
        }
        cout<<endl<<"Time : "<<during<<endl;      //��ܸg�L�ɶ�

        cin>>n;                             //�}�l�U�@������
        start=clock();                      //�U�����D�n�{�����e�}�l
    }
    system("pause");
    return 0;
}
