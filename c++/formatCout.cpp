#include <iostream>
#include<cassert>
#include<cmath>
#include<iomanip>
using namespace std;


int main()
{
    int m=0,n=0;
    while(cin>>n>>m){
        assert(n>=0&&m<=999);
        assert(m>=0&&m<=999);
        double result=0.0,pre=(double)n,next=sqrt(pre);
        for(int i=1;i<=m;++i){
            result+=pre;
            pre=next;
            next=sqrt(pre);
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<result<<endl;
    }
    return 0;
}
