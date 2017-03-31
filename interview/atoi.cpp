#include <iostream>
#include <cctype>
using namespace std;
bool invalidInput=true;
bool invalidStringInput=true;
long long atoiCore(char *ps,bool isMinus){
     long long num=0;
     int flag=isMinus?-1:1;
     while(*ps!='\0'){
        if(isdigit(*ps)){
            if((flag==1&&num>0x7fffffff)||(flag==-1&&num<(signed int)0x80000000)){
                num=0;
                break;
//                return num;
            }
            num=num*10+flag*(*ps-'0');
            ++ps;
        }
        else{
            num=0;
            break;
//            return num;
        }
     }
     if(*ps=='\0')
        invalidInput=false;
     return num;

}
int myatoi(char *ps){
    invalidInput=true;
    long long num=0;
    bool isMinus=false;
    if(ps!=nullptr&&(*ps!='\0')){
        if(*ps=='+'||*ps=='-'){
            isMinus=(*ps=='-')?!isMinus:isMinus;
            ++ps;
        }
        if(*ps!='\0'){
            num=atoiCore(ps,isMinus);
        }
    }
    return (int)num;
}

int myatoi(string str){
    invalidStringInput=false;
    if(str.size()==0||str.find_first_not_of(' ')==string::npos){
        invalidStringInput=true;
        return 0;
    }
    string::size_type pos=str.find_first_not_of(' ');
    int flag=1;
    int num=0;
    if(str[pos]=='+'||str[pos]=='-'){
        flag=(str[pos]=='-')?-1:1;
        ++pos;
        if(pos==str.size()){
            invalidStringInput=true;
            return 0;
        }
    }
    while(pos<str.size()){
        if(isdigit(str[pos])){
            if(num>INT_MAX/10||(num==INT_MAX/10&&(str[pos]-'0')>7)){
                invalidStringInput=true;
                return 0;
            }
            num=num*10+str[pos]-'0';
            ++pos;
        }
        else{
            invalidStringInput=true;
            return 0;
        }
    }
    return num;
}

int main()
{
    char ch[40];
    while(cin>>ch){
        int num=myatoi(ch);
        if(invalidInput)
            cout<<"input invalid"<<endl;
        else
            cout<<num<<endl;
    }

    string str;
    while(cin>>str){
        int num= myatoi(str);
        if(invalidStringInput)
            cout<<"input invalid"<<endl;
        else
            cout<<num<<endl;
    }




    return 0;
}
