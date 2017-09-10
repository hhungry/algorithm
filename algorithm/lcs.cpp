#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string str){
    string str1(str);
    for(auto i=0;i<str1.size()>>1;++i){
        char c=str1[i];
        str1[i]=str1[str1.size()-1-i];
        str1[str1.size()-1-i]=c;
    }
    
    vector<vector<int>> vvec(str1.size()+1,vector<int>(str1.size()+1));

    for(auto i=0;i<str.size();++i){
        for(auto j=0;j<str1.size();++j){
            if(str[i]==str1[j]){
                vvec[i+1][j+1]=vvec[i][j]+1;
            }else if(vvec[i+1][j]>vvec[i][j+1]){
                vvec[i+1][j+1]=vvec[i+1][j];
            }else vvec[i+1][j+1]=vvec[i][j+1];
        }
    }
    return (str.size()-vvec[str1.size()][str1.size()]);
    
}
int main(){
    string str;
    while(cin>>str){
        int deleteNum=lcs(str);
        cout<<deleteNum<<endl;
    }
}
