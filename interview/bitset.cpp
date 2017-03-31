#include <iostream>
#include <bitset>
using namespace std;
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 100

int a[N/32+1];
void setBit(int i){
    a[i>>SHIFT]|=(1<<(i&MASK));
}
void clrBit(int i){
    a[i>>SHIFT]&=~(1<<(i&MASK));
}
int test(int i){
    return (a[i>>SHIFT]&(1<<(i&MASK)));
}
int main()
{
    int i;
    for (i = 0; i < N; i++)
        clrBit(i);
    while (cin>>i){
         setBit(i);
    }
    for(i=0;i<4;++i){
        bitset<32>b(a[i]);
        cout<<b<<endl;
    }
    for (i = 0; i < N; i++)
        if (test(i))
            cout<<i<<endl;
    return 0;
}
