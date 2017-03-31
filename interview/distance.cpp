#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include<limits.h>
using namespace std;

#define MAX_VERTEX_NUM 100
int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


void input(map<string,int> &mmap,int edgenum,int &vexnum){
    for(int i=0;i<MAX_VERTEX_NUM;++i){
        for(int j=0;j<MAX_VERTEX_NUM;++j){
            if(i==j)
                edges[i][j]=0;
            else edges[i][j]=-1;
         }
    }

     string line;
     int i=0;
    //输入信息的处理
     while(edgenum>0){
        cin>>line;

        int pos1=0,pos2=0;
        pos1=line.find_first_of(",");
        pos2=line.find_last_of(",");

        string src=line.substr(0,pos1);
        string des=line.substr(pos1+1,pos2-pos1-1);
        string dis=line.substr(pos2+1);
        int distance=atoi(dis.c_str());

        if(mmap.find(src)==mmap.end())
            mmap[src]=i++;
        if(mmap.find(des)==mmap.end())
            mmap[des]=i++;
        edges[mmap[src]][mmap[des]]=distance;
        --edgenum;
    }
    //节点个数
    vexnum=mmap.size();
}

void Dijkstra(int src,int des,const int vexnum,vector<int> &path){
//    int distance=0;
    //最短距离数组
    int dis[vexnum];
    //标记是否已经找到最短距离
    bool flag[vexnum];
    for(int i=0;i<vexnum;++i)
        dis[i]=edges[src][i];
    for(int i=0;i<vexnum;++i)
        flag[i]=false;
    flag[src]=true;
    path[src]=-1;
    for(int i=1;i<vexnum;++i){
        int mindis=INT_MAX;
        int minloc=-1;
        for(int j=0;j<vexnum;++j){
            if((!flag[j])&&(dis[j]>=0)&&(dis[j]<mindis)){
                mindis=dis[j];
                minloc=j;
            }
        }
        if(i==1){
            path[minloc]=src;
        }
        flag[minloc]=true;
        if(minloc==des){
//          distance=mindis;
            break;
        }

        for(int j=0;j<vexnum;++j){
            if(edges[minloc][j]!=-1){
                if(dis[j]==-1){
                    dis[j]=edges[minloc][j]+mindis;
                    path[j]=minloc;
                }
                else if(dis[j]>(edges[minloc][j]+mindis)){
                    dis[j]=edges[minloc][j]+mindis;
                    path[j]=minloc;
                }

            }
        }
    }
//    return distance;

}
int main()
{
    int edgenum=0;
    int vexnum=0;
    map<string,int> mmap;//字符串到id的映射
    map<int,string> mmap1;

    while(cin>>edgenum){
        mmap.clear();
        mmap1.clear();
        input(mmap,edgenum,vexnum);
        //记录用id标示的路径
        vector<int> path(vexnum,-2);
        //获得标号到字符串的映射
        for(map<string,int>::iterator it=mmap.begin();it!=mmap.end();++it)
            mmap1[it->second]=it->first;

//        int src=mmap["v0"];
//        int des=mmap["v5"];
          int src=0;//mmap["v0"];
          int des=5;//mmap["v5"];

        Dijkstra(src,des,vexnum,path);
        int value=des;
        vector<string> spath;
        while((value!=-1)&&(value!=-2)){
            spath.push_back(mmap1[value]);
            value=path[value];
        }
        for(int ix=spath.size()-1;ix>=0;--ix){
            cout<<spath[ix];
            if(ix!=0) cout<<"->";
        }
        cout<<endl;


    }

    return 0;
}


