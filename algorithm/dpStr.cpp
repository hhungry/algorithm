#include <iostream>
#include<algorithm>
using namespace std;

int LCSequence(char *str1,int len1,char *str2,int len2){
    int **dp=new int*[len1];
    for(int i=0;i<len1;++i)
        dp[i]=new int[len2];

    for(int i=0;i<len1;++i){
        for(int j=0;j<len2;++j){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[len1-1][len2-1];
}

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
