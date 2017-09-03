#include <iostream>
#include <string>
#include<sstream>
#include<assert.h>
using namespace std;
//字符串全排列
void permutation(char *str,char *pbegin){
    if(*pbegin=='\0')
        cout<<str<<endl;
    else{
        for(char *pc=pbegin;*pc!='\0';++pc){
            char tmp=*pbegin;
            *pbegin=*pc;
            *pc=tmp;
            permutation(str,pbegin+1);
            tmp=*pbegin;
            *pbegin=*pc;
            *pc=tmp;
        }
    }

}
void permutation(char *str){
    if(str==NULL||*str=='\0')
        return ;
    permutation(str,str);

}

//字符串全排列2：
void Permutation(char *pstr,int from,int to){
    if(from==to)
        cout<<pstr<<endl;
    for(int i=from;i<=to;++i){
        swap(pstr[from],pstr[i]);
        Permutation(pstr,from+1,to);
        swap(pstr[from],pstr[i]);
    }
}
void Permutation(char *pstr){
    if(pstr&&*pstr!='\0'){
        int from=0;
        int to=strlen(pstr)-1;
        Permutation(pstr,from,to);
    }
}

//数字全排列
void permutation(int *data,int *pbegin,const int len,int sublen){
    if(sublen==0){
        for(int i=0;i<len;++i)
            cout<<data[i]<<" ";
        cout<<endl;
    }
    else{
        for(int *pcurr=pbegin;pcurr<pbegin+sublen;++pcurr){
            int tmp=*pcurr;
            *pcurr=*pbegin;
            *pbegin=tmp;
            permutation(data,pbegin+1,len,sublen-1);
            tmp=*pcurr;
            *pcurr=*pbegin;
            *pbegin=tmp;
        }
    }

}
void permutation(int *data,int len){
    if(!data||len<=0)
        return ;
    int sublen=len;
    permutation(data,data,len,sublen);

}


int main()
{
    int a[5]={1,2,3,4,5};
    permutation(a,5);
//    char str[]="abcd";
//    permutation(str);
    return 0;
}
