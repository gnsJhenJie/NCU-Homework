#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

int Threshold=28;       //設定Threshold的值，目前測試為27~29的時候，40000筆隨機測資平均所花的時間最短，約為28毫秒，沒有精密計算不好意思

void insertionSortForX(int *data,int *dataY,int *dataN,int *dataC,int length){      //對X的Insertion Sort
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

void insertionSortForN(int *data,int *dataC,int length){        //對次序的Insertion Sort
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
//對X值的Merge合併
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
//對X值的Merge Sort
void mergeSortForX(int *data,int *dataY,int *dataN,int *dataC,int length){
    if(length>1){
        if(length<=Threshold){                      //若傳進來的陣列長度小於Threshold，改用insertion sort進行排序
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
//對Y值的Merge合併
void mergeForY(int *sortedData,int *sortedDataN,int *sortedDataC,int *left,int *right,int *leftN,int *rightN,int *leftC,int *rightC,int leftl,int rightl){
    int leftIndex=0,rightIndex=0;
    for(int i=0;i<leftl+rightl;i++){
        if(leftIndex==leftl){
            rightC[rightIndex]+=leftIndex;      //右邊併進去，計算其rank值
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
            rightC[rightIndex]+=leftIndex;      //右邊併進去，計算其rank值
            sortedDataN[i]=rightN[rightIndex];
            sortedDataC[i]=rightC[rightIndex];
            sortedData[i]=right[rightIndex++];
        }
    }
}
//對Y值的Merge Sort
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
//對次序的Merge合併
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
//對次序的Merge Sort
void mergeSortForN(int *data,int *dataC,int length){
    if(length>1){
        if(length<=Threshold){                      //若傳進來的陣列長度小於Threshold，改用insertion sort進行排序
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
    clock_t start,finish;       //start=開始時間 finish=一系列merge sort&insertion sort 執行完後的時間
    double during;              //during=開始至結束之間的時間
    srand( (unsigned)time(NULL) );
    cin>>n;
    while(n!=0){
        for(int number[n],x[n],y[n],c[n]={0},i=0;i<n;i++){      //依照輸入的n值宣告n長度的 次序,x,y,rank 陣列
            number[i]=i;
            cin>>x[i];      //如需手動輸入測資測試，請將這兩行註解拿掉並註解掉下面rand兩行
            cin>>y[i];      //
            //x[i]=rand()%10000;      //因為用大量測資，隨機比較方便，如需測試Threshold可將這兩行註解拿掉並註解掉上面cin兩行
            //y[i]=rand()%10000;
            start=clock();          //主要的程式內容開始
            if(i==n-1){
                mergeSortForX(x,y,number,c,n);      //先對X值做排序
                mergeSortForY(y,number,c,n);        //在對Y值做排序
                mergeSortForN(number,c,n);          //各測資已有各自的rank值，用次序排序回來原本輸入的順序
                finish=clock();                     //主要的程式內容結束
                during=(double)finish-start;        //計算經過時間
                cout<<endl<<"rank值: ";
                for(int j=0;j<n;j++){       //輸出依次序排序過的rank值，如需測試Threshold建議將此for註解掉直接看花多少時間
                    cout<<c[j]<<" ";
                }
            }
        }
        cout<<endl<<"Time : "<<during<<endl;      //顯示經過時間

        cin>>n;                             //開始下一次測試
        start=clock();                      //下次的主要程式內容開始
    }
    system("pause");
    return 0;
}
