#include <iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<functional>
#include<map>
#include<utility>
using namespace std;


bool compare(pair<int,int>& com1,pair<int,int>& com2){
    return (com1.first>=com2.first)||(com1.second>=com2.second);
}
void findMax(vector<pair<int,int>>& vec,vector<pair<int,int>>& result){
    int len=vec.size();
    int i=0,j=0;
    for(i=0;i<len;++i){
        for(j=0;j<len;++j){
            if(compare(vec[i],vec[j])){
               continue;
            }
            else
                break;
        }
        if(j==len)
            result.push_back(vec[i]);
    }
}
int main()
{
    vector<pair<int,int>>vec;
    pair<int,int> mpair;
    while(cin>>mpair.first>>mpair.second){
        vec.push_back(mpair);
    }

    //存放所有的最大值
    vector<pair<int,int>> result;
    findMax(vec,result);

    for(auto ele:result)
        cout<<ele.first<<"\t"<<ele.second<<endl;

    return 0;
}
