#include<iostream>
#include<cstring>
using namespace std;

class A{
public:
    char str[80];
    A(const char *s){
        strcpy(str,s);
    }
    A operator+=(A a){
        strcat(str,a.str);
        return *this;
    }
    void chng(){
        str[0]='p';
    }
};

int main(){
    A obj("123"),obj1("456");
    obj+=obj1;
    cout<<obj.str<<endl;

    obj.chng();
    cout<<obj.str<<endl;


}
