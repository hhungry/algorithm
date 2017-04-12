#include <iostream>
#include <string>
#include<sstream>
#include<assert.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int Longest_Substr_Norepeat(char *str){
    int hsh[256];
    for(auto &ele:hsh)
        ele=-1;
    int len=strlen(str);
    int maxlen=0;
    int start=-1;
    for(int i=0;i<len;++i){
        if(hsh[str[i]]>start)
            start=hsh[str[i]];
        hsh[str[i]]=i;
        maxlen=maxlen>(i-start)?maxlen:(i-start);
    }
    return maxlen;
}
int Longest_Substr_Norepeat(string str){
    vector<int> hsh(256,-1);
    int start=-1;
    int maxlen=0;
    for(int ix=0;ix!=str.size();++ix){
        if(hsh[str[ix]]>start)
            start=hsh[str[ix]];
        hsh[str[ix]]=ix;
        maxlen=max(maxlen,ix-start);
    }
    return maxlen;
}
int main()
{
   string str;
   while(cin>>str)
    cout<<Longest_Substr_Norepeat(str)<<endl;
    return 0;
}
