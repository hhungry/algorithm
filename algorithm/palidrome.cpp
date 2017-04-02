#include <iostream>
#include <string>
#include<sstream>
#include<assert.h>
using namespace std;
//longest palindrome len and substr
string longestPalindrome(string s)
{
    int i=0,j=0,maxLen=0,c=0;
    int pbegin=0,pend=0;

    for(i=0;i<s.size();++i)
    {
        for(j=0; (i-j)>=0&&(i+j)<s.size(); ++j)
        {
            if(s[i-j]!=s[i+j])
                break;
            c=2*j+1;
        }
        if(c>maxLen)
        {
            maxLen=c;
            pbegin=(i-j+1)>=0?(i-j+1):pbegin;
            pend=(i+j-1)<s.size()?(i+j-1):pend;
        }

        for(j=0; (i-j)>=0&&(i+j+1)<s.size(); ++j)
        {
            if(s[i-j]!=s[i+j+1])
                break;
            c=2*j+2;
        }
        if(c>maxLen)
        {
            maxLen=c;
            pbegin=(i-j+1)>=0?(i-j+1):pbegin;
            pend=(i+j)<s.size()?(i+j):pend;
        }
    }
    string sub=s.substr(pbegin,pend-pbegin+1);
    return sub;
}
int main()
{
    string str;
    while(cin>>str){
        cout<<longestPalindrome(str)<<endl;
    }
    return 0;
}
