#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;


int getIndex(string str1,string str2){
    if(str1.size()==0||str2.size()==0||str1.size()<str2.size())
        return -1;
    int i=0,j=0;
    while(i<str1.size()&&j<str2.size()){
        if(str1[i]==str2[j]){
            ++i;
            ++j;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==str2.size()){
        return (i-j);
    }
    else return -1;
}

int main() {
    string str1="abcdefg";
    string str2="fd";
    int rst=getIndex(str1,str2);
    cout<<rst<<endl;
}
