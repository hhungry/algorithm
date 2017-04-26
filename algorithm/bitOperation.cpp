#include<iostream>
#include<bitset>
#include<climits>
#include<cstdio>
using namespace std;

//swap two nums
void swap_self(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

//abs
int my_abs(int a){
    int i = a >> 31;
	return i == 0 ? a : (~a + 1);
}
int my_abs1(int a){
    int i = a >> 31;
    return ((a ^ i) - i);
}

//add two num
int add(int num1,int num2){
    int sum=0,carry=0;
    do{
        sum=num1^num2;
        carry=(num1&num2)<<1;
        num1=sum;
        num2=carry;
    }while(num2!=0);
    return sum;
}
//print the binary of a number
template <class T>
void PrintfBinary(T a)
{
    int i;
    for (i=sizeof(a)*8-1;i>=0;--i)
    {
        if((a>>i)&1)
            putchar('1');
        else
            putchar('0');
        if(i%8==0)
            putchar(' ');
    }
    putchar('\n');
}

//the number of 1
template <class T>
int numOf1(T a){
    int cnt=0;
    while(a){
        ++cnt;
        a=a&(a-1);
    }
    return cnt;
}
int main ()
{
//    int a=0;
//    cout<<sizeof(a)<<endl;
//    cout<<bitset<32>(INT_MAX)<<endl;
//    cout<<bitset<32>(INT_MIN)<<endl;
//    while(cin>>a){
//        cout<<bitset<32>(a)<<endl;
//        cout<<bitset<32>(a>>1)<<endl;
//        cout<<bitset<32>(a<<1)<<endl;
//        cout<<bitset<32>(a>>31)<<endl;
//    }
//    int a=0;
//    while(cin>>a)
//        PrintfBinary(a);

    unsigned long long lval=1;
    cout<<bitset<64>(lval<<63)<<endl;
    lval=lval<<63;
     cout<<bitset<64>(lval<<1)<<endl;

    return 0;
}
