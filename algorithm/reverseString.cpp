#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
#include<cstring>
#include<sstream>

void reverseString(char *pbegin,char *pend)
{
    if(pbegin==NULL||pend==NULL)
        return ;
    while(pbegin<pend)
    {
        swap(*pbegin,*pend);
        ++pbegin;
        --pend;
    }
}

void reverseString(char *str,int len)
{
    if(str==NULL||len<=0)
        return ;

    reverseString(str,str+len-1);
    char *pbegin=str;
    char *pend=str;
    while(*pbegin!='\0')
    {
        if(*pbegin==' ')
        {
            ++pbegin;
            ++pend;
        }
        /*
	no:reverseString(pbegin,pend-1);begin=pend+1;
        yes:reverseString(pbegin,pend-1);begin=pend;
        */
        else if(*pend==' '||*pend=='\0')
        {
            reverseString(pbegin,pend-1);
            pbegin=pend;
        }
        else
        {
            ++pend;
        }
    }
}

void reverseString(char *str){
    if(str==NULL||*str=='\0')
        return ;
    char *pbegin=str;
    char *pend=str;
    while(*pend!='\0')
        ++pend;
    --pend;
    reverseString(pbegin,pend);
    pbegin=str;
    pend=str;
    while(*pbegin!='\0')
    {
        if(*pbegin==' ')
        {
            ++pbegin;
            ++pend;
        }
        else if(*pend==' '||*pend=='\0')
        {
            reverseString(pbegin,pend-1);
            pbegin=pend;
        }
        else
        {
            ++pend;
        }
    }

}
int main()
{

    char str[100]= {"I           am a  student."};

//    int len=strlen(str);
//    cout<<"len:"<<len<<endl;
//    reverseString(str,len);
//    cout<<str<<endl;

    reverseString(str);
    cout<<str<<endl;
}

