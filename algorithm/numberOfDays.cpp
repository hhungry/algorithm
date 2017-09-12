#include<iostream>
#include<cstring>
#include<string>
#include<assert.h>
using namespace std;

int numberOfDays(int numOfPlants,int plantHeight[]){
    assert(numOfPlants>=2&&numOfPlants<=1e5);
    assert(plantHeight!=nullptr);

    int currNum=numOfPlants;
    int cnt=0;
    bool *hsh=new bool[currNum];
    for(int i=0;i<currNum;++i)
        hsh[i]=false;
    int flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<currNum-1;++i){
            if(plantHeight[i+1]>plantHeight[i]){
                hsh[i+1]=true;
                flag=true;
            }
        }
        if(flag==false)
            break;
        int j=0;
        for(int i=0;i<currNum;++i){
            if(hsh[i])
                continue;
            else plantHeight[j++]=plantHeight[i];
        }
        currNum=j;
        for(int i=0;i<currNum;++i)
            hsh[i]=false;
        ++cnt;
    }
    return cnt;

}
int main(void)
{
    int plantHeight[]={3,3,6,7,8};
    int numOfPlants=5;
    int ret=numberOfDays(numOfPlants,plantHeight);
    cout<<ret<<endl;
}
