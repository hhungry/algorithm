#include <iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int compTime(pair<int,int> &currLoc,pair<int,int> &carLoc,pair<int,int> &comLoc,int walkTime,int busTime){
    int dis1=abs(carLoc.first-currLoc.first)+abs(carLoc.second-currLoc.second);//walking
    int dis2=abs(comLoc.first-carLoc.first)+abs(comLoc.second-carLoc.second);//car dis
    int time=dis1*walkTime+dis2*busTime;
    return time;
}
int main()
{
    int n=0;//打车点个数
    while(cin>>n){
        map<int,int> mymap;
        vector<int> xvec;
        vector<int> yvec;
        int value=0;
        for(int i=0;i<n;++i){
            cin>>value;
            xvec.push_back(value);
        }
        for(int i=0;i<n;++i){
            cin>>value;
            yvec.push_back(value);
        }
        for(int i=0;i<n;++i){
            mymap.insert(make_pair(xvec[i],yvec[i]));
        }

        int x=0,y=0;
        cin>>x>>y;
        pair<int,int> comLoc(x,y);//公司位置

        int walkTime=0,busTime=0;
        cin>>walkTime>>busTime;

        pair<int,int> currLoc(0,0);//当前位置

        vector<int> timeVec;
        int time=0;
        for(map<int,int>::iterator it=mymap.begin();it!=mymap.end();++it){
            pair<int,int> carLoc(it->first,it->second);
            time=compTime(currLoc,carLoc,comLoc,walkTime,busTime);
            timeVec.push_back(time);
        }
        sort(timeVec.begin(),timeVec.end());

        int minWalkTime=(abs(comLoc.first-currLoc.first)+abs(comLoc.second-currLoc.second))*walkTime;
        int minTime=minWalkTime<timeVec[0]?minWalkTime:timeVec[0];
        cout<<minTime<<endl;
    }
    return 0;
}
