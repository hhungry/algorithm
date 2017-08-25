#include <iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<functional>
#include<map>
#include<utility>
#include<stack>
#include<cstring>
using namespace std;

//len的校验，因为src之后的字符个数可能小于len？？
void* memmove_self(void *des,void *src,size_t len){
    if(!des||!src)
        return nullptr;
    void *ret=des;
    if(des==src)
        return ret;
    else if(des<src||des>=(char *)src+len){
        while(len--){
            *(char *)des=*(char *)src;
            des=(char *)des+1;
            src=(char *)src+1;
        }
    }else{
        des=(char *)des+len-1;
        src=(char *)src+len-1;
        while(len--){
            *(char *)des=*(char *)src;
            des=(char *)des-1;
            src=(char *)src-1;
        }
    }
    return ret;
}

//考虑字符数组的'\0'，比如执行memmove_self(a+1,a,10);之后，再执行a数组的输出，因为最后一个字符没有置为'\0'，所以可能会输出乱码
int main()
{
    char a[]="abcdefg";
    memmove_self(a+3,a,3);
    cout<<a<<endl;
}




