#include <iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<functional>
#include<map>
using namespace std;
template<class Pair>
struct select1st:public unary_function<Pair,typename Pair::first_type>{
    const typename Pair::first_type& operator()(const Pair& x) const{
            return x.first;
    }
};

template<class Pair>
struct select2st:public unary_function<Pair,typename Pair::second_type>{
    const typename Pair::second_type& operator()(const Pair &x) const{
        return x.second;
    }
};

template<class T>
struct identity:public unary_function<T,T>{
    const T& operator()(const T& x) const{
        return x;
    }
 };


int main()
{
    vector<int> inputArr={3,1,5,7,2,4,9,6};
    sort(inputArr.begin(),inputArr.end(),greater_equal<int>());
    for(auto ele:inputArr)
        cout<<ele<<" ";
    cout<<endl;

    pair<int,int> mpair{1,2};
    select2st<pair<int,int>> s;
    int val=s(mpair);
    cout<<val<<endl;

    pair<int,int>::first_type val1=10;
    cout<<val1<<endl;

    int a=10;
    int b=identity<int>()(a);
    cout<<b<<endl;

}
