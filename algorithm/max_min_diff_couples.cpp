#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n){
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        vector<int> data(n);
        for(int i=0;i<n;++i)
            cin>>data[i];
        sort(data.begin(),data.end());

        map<int,int> mmap;
        for(int i=0;i<n;++i){
            if(mmap.count(data[i]))
                ++mmap[data[i]];
            else mmap[data[i]]=1;
        }

        int maxCouple=mmap[data[0]]*mmap[data[n-1]];
        int minCouple=0;
        int minValue=INT_MAX;
        for(int i=1;i<n;++i){
            if(data[i]-data[i-1]<minValue)
                minValue=data[i]-data[i-1];
        }
        if(minValue==0){
            for(map<int,int>::iterator it=mmap.begin();it!=mmap.end();++it){
                if(it->second>=2){
                    minCouple=minCouple+(it->second*(it->second-1))/2;
                }
            }
        }
        else{
            map<int,int>::iterator pre=mmap.begin();
            map<int,int>::iterator post=pre;
            ++post;
            for(;post!=mmap.end();++post){
                if(post->first-pre->first==minValue){
                    minCouple=minCouple+(post->second*pre->second);
                }
                else{
                    pre=post;
                }
            }
        }
        cout<<minCouple<<" "<<maxCouple<<endl;
    }

    return 0;
}
