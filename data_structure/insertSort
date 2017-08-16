#include <iostream>
#include<vector>
using namespace std;
void insertSort(vector<int> &inputArr){
    for(int i=1;i<inputArr.size();++i){
        int tmp=inputArr[i];
        int j=i-1;
        for(;j>=0;--j){
            if(inputArr[j]>tmp){
                inputArr[j+1]=inputArr[j];
            }
            else{
                inputArr[j+1]=tmp;
                break;
            }
        }
        inputArr[j+1]=tmp;
        for(auto ele:inputArr)
            cout<<ele<<" ";
        cout<<endl;
    }
}
void insertSort1(vector<int> &inputArr){
    for(int i=1;i<inputArr.size();++i){
        int tmp=inputArr[i];
        int j=i-1;
        while(j>=0&&inputArr[j]>tmp){
            inputArr[j+1]=inputArr[j];
            --j;
        }
        inputArr[j+1]=tmp;
        for(auto ele:inputArr)
            cout<<ele<<" ";
        cout<<endl;
    }
}
int main()
{
    vector<int> inputArr={3,1,5,7,2,4,9,6};
    insertSort1(inputArr);
    for(auto ele:inputArr)
        cout<<ele<<" ";
    cout<<endl;
}
