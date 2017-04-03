#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;
int mostFrenquent(unsigned int *data,unsigned int len){
    int number=0;
    unsigned int curr=data[0];
    for(int i=1;i<len;++i){
        if(data[i]==curr)
            ++number;
        else if(number==0){
            curr=data[i];
            number=1;
        }
        else{
            --number;
        }
    }
    if(number==0)
        return -1;
    else return curr;

}
bool judge(unsigned int *data,unsigned int len,unsigned int result){
    int number=0;
    for(int i=0;i<len;++i){
        if(data[i]==result)
            ++number;
    }
    if(number>result/2)
        return true;
    else return false;
}
int main()
{
    unsigned int n=0;
    while(cin>>n){
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        unsigned int *data=new unsigned int[n];
        for(int i=0;i<n;++i)
            cin>>data[i];
        unsigned int result=mostFrenquent(data,n);
        if(result==-1)
            cout<<0<<endl;
        else if(judge(data,n,result))
            cout<<result<<endl;
        else cout<<0<<endl;

    }
   return 0;
}
