#include <iostream>
#include<vector>
using namespace std;
void heapAdjust(vector<int>&inputArr,int topIndex,int len){
    int topValue=inputArr[topIndex];
    int leftChild=2*topIndex+1;
    while(leftChild<len){
        if(leftChild+1<len&&inputArr[leftChild+1]>inputArr[leftChild])
            ++leftChild;
        if(topValue>inputArr[leftChild])
            break;
        inputArr[topIndex]=inputArr[leftChild];
        topIndex=leftChild;
        leftChild=2*topIndex+1;
    }
    inputArr[topIndex]=topValue;
}
void heapSort(vector<int> &inputArr){
    int len=inputArr.size();
    //建堆
    for(int i=(len-2)/2;i>=0;--i){
        heapAdjust(inputArr,i,len);
    }

    for(int i=len-1;i>0;i--){
        int tmp=inputArr[0];
        inputArr[0]=inputArr[i];
        inputArr[i]=tmp;
        heapAdjust(inputArr,0,i);
    }

}
int main()
{
    vector<int> inputArr{49,38,65,97,76,13,27};
    heapSort(inputArr);
    for(auto ele:inputArr)
        cout<<ele<<" ";
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
