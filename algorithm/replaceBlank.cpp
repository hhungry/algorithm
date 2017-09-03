#include<iostream>
#include<cstring>
using namespace std;

//length表示数组可容纳元素数量，不包括'\0'
void replaceBlank(char str[],int length){
    if(str==nullptr||length<=0)
        return ;

    int oldLen=0;
    int numBlank=0;
    char *p=str;
    while(*p!='\0'){
        ++oldLen;
        if(*p==' '){
            ++numBlank;
        }
        ++p;
    }

    int newLen=oldLen+2*numBlank;
    //当没有空格或者数组空间不够容纳新字符串时，退出
    if(newLen>length||numBlank==0)
        return ;
        
//用newLen与oldLen的比较，说明当前位置之前是否有空格
    while(oldLen>=0&&newLen>oldLen){
        if(str[oldLen]==' '){
            str[newLen--]='0';
            str[newLen--]='2';
            str[newLen--]='%';
            --oldLen;
        }else{
            str[newLen--]=str[oldLen--];
        }
    }

}


int main(){
    char str[101]="we are happy. ";
    cout<<strlen(str)<<endl;
    replaceBlank(str,100);
    cout<<str<<endl;
}
