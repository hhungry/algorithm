#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<functional>
#include<algorithm>
using namespace std;
template <class T>
struct is_pos:public unary_function<T,bool>{
    bool operator()(const T& value) const{
        return value>0?true:false;
    }
};

template<class T>
struct add_self:public binary_function<T,T,T>{
    T operator()(const T& arg1,const T& arg2)const{
        return (arg1+arg2);
    }
};
int main(){
    vector<int> ivec={10,15,8,200,-5};
    sort(ivec.begin(),ivec.end(),greater<int>());
    for(auto ele:ivec)
        cout<<ele<<" ";
    cout<<endl;

    int count_pos=0;
    //not1：模板函数
    count_pos=count_if(ivec.begin(),ivec.end(),not1(is_pos<int>()));
    cout<<count_pos<<endl;

    //bind1st：模板函数
    cout<<bind1st(add_self<int>(),10)(5);
}

