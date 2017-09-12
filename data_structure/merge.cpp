#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool invalidInput=false;
bool invalidInputNRecursive=false;

void mergeSort(vector<int> &src,vector<int> &des,int i,int m,int n){
    int k=0,j=0;
    for(k=i,j=m+1;i<=m&&j<=n;++k){
        if(src[i]<=src[j]){
            des[k]=src[i];
            ++i;
        }
        else{
            des[k]=src[j];
            ++j;
        }
    }
    while(i<=m) des[k++]=src[i++];
    while(j<=n) des[k++]=src[j++];
}

void msort_recursive(vector<int> &src,vector<int>&des,int low,int high){
    if(src.size()==0||des.size()==0||src.size()!=des.size()||low<0||high<0||low>high){
        invalidInput=true;
        return ;
    }

    if(low==high)
        des[low]=src[low];
    else{
        vector<int> tmp(src.size());
        int mid=(low+high)>>1;
        msort_recursive(src,tmp,low,mid);
        msort_recursive(src,tmp,mid+1,high);
        mergeSort(tmp,des,low,mid,high);
    }
}
void msort_nonrecursive(vector<int> &src,vector<int>&des){
    if(src.size()==0||des.size()==0||src.size()!=des.size()){
        invalidInputNRecursive=true;
        return ;
    }
    int elenum=src.size();
    int len=1;
    //¿½±´¹¹Ôì
    vector<int>tmp(src);
    while(len<elenum){
        int s=len;
        len=s<<1;
        int i=0;
        while(i+len<=elenum){
            mergeSort(tmp,des,i,i+s-1,i+len-1);
            i=i+len;
        }
        if(i+s<elenum){
            mergeSort(tmp,des,i,i+s-1,elenum-1);
        }
        tmp=des;
    }
}
void mSort_nonrecursive(vector<int> &src){
    if(src.size()==0||src.size()==1)
        return ;
    int num=src.size();
    int len=1;
    int s=0;
    vector<int> des(src.size());
    while(len<num){
        s=len;
        len=s<<1;
        int i=0;
        while(i+len<=num){
            mergeSort(src,des,i,i+s-1,i+len-1);
            i=i+len;
        }
        if(i+s<num)
            mergeSort(src,des,i,i+s-1,num-1);
        src=des;
    }
}
int main()
{
    vector<int> ivec={49,38,65,97,76,13,27,1,10,23,89,-1,118};
    vector<int> ivec1(ivec);
    int low=0;
    int high=ivec.size()-1;
    msort_recursive(ivec,ivec,low,high);
    for(auto &elem:ivec)
        cout<<elem<<" ";
    cout<<endl;

    msort_nonrecursive(ivec1,ivec1);
    for(auto &elem:ivec1)
        cout<<elem<<" ";
    cout<<endl;


    return 0;
}
