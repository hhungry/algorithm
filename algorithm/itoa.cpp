#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

//可以用streamstring简易实现，此处为手动实现代码
void inversion(char *str){
    int len=strlen(str);
    int i=0,j=len-1;
    while(i<j){
        swap(str[i],str[j]);
        ++i;
        --j;
    }
}

int main(){
   int num=0;
   char str[33];
   int curr=0;
   while(cin>>num){
        
        while(num){
            str[curr]='0'+num%10;
            num=num/10;
            ++curr;
        }
        str[curr]='\0';
        cout<<str<<endl;
        inversion(str);
        cout<<str<<endl;
        
        curr=0;
   }
}
