#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

//all combination
void printAllCombination(char *str){
    if(!str||*str=='\0')
        return ;
    int len=strlen(str);
    int n=1<<len;
    for(int i=1;i<n;++i){
        for(int j=0;j<len;++j){
            int tmp=i;
            if(tmp&(1<<j))
                cout<<str[j];
        }
        cout<<endl;
    }
}
int main(){
   char str[]="abcd";
   printAllCombination(str);
}

