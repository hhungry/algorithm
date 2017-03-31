#include <iostream>
#include <stdio.h>
#include<vector>
#include<string>
using namespace std;
void rotate_cube(vector<int> &init,char c){
    int left=init[0],right=init[1],pre=init[2],bac=init[3],up=init[4],down=init[5];
    if(c=='L'){

        init[0]=up;
        init[1]=down;
        init[4]=right;
        init[5]=left;

    }
    else if(c=='R'){
        init[0]=down;
        init[1]=up;
        init[4]=left;
        init[5]=right;
    }
    else if(c=='F'){
        init[2]=up;
        init[3]=down;
        init[4]=bac;
        init[5]=pre;
    }
    else if(c=='B'){
        init[2]=down;
        init[3]=up;
        init[4]=pre;
        init[5]=bac;
    }
    else if(c=='C'){
        init[0]=pre;
        init[1]=bac;
        init[2]=right;
        init[3]=left;
    }
    else if(c=='A'){
        init[0]=bac;
        init[1]=pre;
        init[2]=left;
        init[3]=right;
    }
}
int main(){
    vector<int> init(6);
    string str;
    while(cin>>str){
        for(vector<int>::size_type ix=0;ix<init.size();++ix){
            init[ix]=ix+1;
        }
        for(string::size_type ix=0;ix!=str.size();++ix){
            rotate_cube(init,str[ix]);
        }
        for(vector<int>::size_type ix=0;ix!=init.size();++ix)
            cout<<init[ix];
        cout<<endl;
    }
    return 0;
}
