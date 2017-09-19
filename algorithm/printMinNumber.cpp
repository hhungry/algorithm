#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
bool compare(const string &str1,const string &str2){
    string::size_type i=0,j=0;
    for(;i<str1.size()&&j<str2.size();++i,++j){
        if(str1[i]<str2[j])
            return true;
        else if(str1[i]==str2[j]){
            continue;
        }else{
            return false;
        }
    }
    if(i<str1.size())
        return true;
    if(j<str2.size())
        return false;
}

bool compare(const string &str1,const string &str2){
    string str1str2=str1+str2;
    string str2str1=str2+str2;
    if(str1str2>str2str1)
        return true;
    else return false;
}

void printMinNumber(vector<int> &vec){
    if(vec.size()==0)
        return ;
    stringstream ss;
    string str;
    vector<string> svec;
    for(int i=0;i<vec.size();++i){
        ss<<vec[i];
        ss>>str;
        svec.push_back(str);
        ss.clear();
        ss.str("");
    }
    sort(svec.begin(),svec.end(),compare);
    for(auto ele:svec)
        cout<<ele<<" ";
    cout<<endl;

}
int main(){

   vector<int> vec={1234,42,321};
   printMinNumber(vec);
}
