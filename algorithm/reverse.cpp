#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

void reverse_int(int &num){
    int data=0;
    while(num){
        data=data*10+num%10;
        num=num/10;
    }
    num=data;

}
void sreverse_int(int &num){
     stringstream is;
     string str;
     is<<num;
     is>>str;

     is.clear();
     is.str("");

     for(int i=0;i<str.size()>>1;++i){
         char temp=str[i];
         str[i]=str[str.size()-i-1];
         str[str.size()-i-1]=temp;
     }
     is<<str;
     is>>num;
 }
int main(){
   int a=198700,b=a;
   reverse_int(a);
   sreverse_int(b);
   cout<<a<<" "<<b<<endl;
}

