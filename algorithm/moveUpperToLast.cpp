#include <iostream>
#include <string>
#include<cctype>
using namespace std;
void moveString(string &str){
    string::size_type len=str.size();

    for(int i=len-1;i>=0;--i){
        int curr=0;
        int j=0;
        for(j=i;j>=0;--j){
            if(isupper(str[j])){
                curr=j;
                break;
            }
        }

        if(j==-1)
            break;
        if(curr==i)
            continue;
        char c=str[curr];
        for(int k=curr;k<i;++k)
            str[k]=str[k+1];
        str[i]=c;
    }
}
int main()
{
    string str;
    while(cin>>str){
        moveString(str);
        cout<<str<<endl;
    }
    return 0;
}
