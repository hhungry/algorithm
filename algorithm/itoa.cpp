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
    if(*str=='-')
        i=1;
    while(i<j){
        swap(str[i],str[j]);
        ++i;
        --j;
    }
}

int main(){
   int num=0;
   long long lnum=0;
   char str[20];
   int curr=0;
//   cout<<INT_MIN<<endl;
//   long long i=INT_MIN;
//   cout<<-i<<endl;
   while(cin>>num){
        if(num==0){
            str[curr++]='0';
            str[curr]='\0';
            cout<<str<<endl;
            curr=0;
            continue;
        }
        if(num<0){
            str[curr++]='-';
            //INT_MIN的相反数已经超出整数表示范围，所以提前转型为long long，再做相反数处理
            lnum=-(long long)num;
           //cout<<lnum<<endl;
            while(lnum){
                str[curr++]='0'+lnum%10;
                lnum=lnum/10;
            }
            str[curr]='\0';
        }else{
            while(num){
                str[curr++]='0'+num%10;
                num=num/10;
            }
            str[curr]='\0';
        }
        cout<<str<<endl;
        inversion(str);
        cout<<str<<endl;
        curr=0;
   }
}


//当value为INT_MIN时，注意防止溢出
string intToStr(int value){
    string str;
    bool isMinus=(value<0)?true:false;
    long long lnum=value>=0?value:-(long long)value;
    if(lnum==0){
        str=str+'0';
    }else{
        while(lnum){
            char c=lnum%10+'0';
            str=str+c;
            lnum=lnum/10;
        }
        reverse(str.begin(),str.end());
        if(isMinus)
            str='-'+str;
    }
    return str;
}
