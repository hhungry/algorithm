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


//最长公共子串
int LCSubstr(char *str1,int len1,char *str2,int len2){
    int **dp=new int*[len1];
    for(int i=0;i<len1;++i)
        dp[i]=new int[len2];

    int maxlen=0;
    for(int i=0;i<len1;++i){
        for(int j=0;j<len2;++j){
            if(str1[i]==str2[j]){
                if(i&&j)
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=1;
                if(dp[i][j]>maxlen)
                    maxlen=dp[i][j];
            }
            else dp[i][j]=0;
        }
    }
    return maxlen;

}
