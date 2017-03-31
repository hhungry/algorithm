
#include<iostream>
#include<vector>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<time.h>
using namespace std;

bool invalidInput=false;
bool invalidInputNRecursive=false;
/**�������Ϊ�����֣���pivot��ߵĲ��ֶ�С�����ұߵĲ���**/
template <typename Comparable>
int partition(vector<Comparable> &vec,int low,int high){
    Comparable pivot=vec[low];  //��ѡԪ����Ϊ�ᣬ����ѡ��Ԫ��
    while(low<high){
        while(low<high && vec[high]>=pivot)
            high--;
        vec[low]=vec[high];
        while(low<high && vec[low]<=pivot)
            low++;
        vec[high]=vec[low];
    }
    //��ʱlow==high
    vec[low]=pivot;
    return low;
}

/**ʹ�õݹ��������**/
template<typename Comparable>
void quicksort1(vector<Comparable> &vec,int low,int high){
    //������
    if(vec.size()==0||low<0||high<0||low>high){
        invalidInput=true;
        return ;
    }
    if(low==high)
        return ;
    if(low<high){
        int mid=partition(vec,low,high);
        if(low<mid-1)
            quicksort1(vec,low,mid-1);
        if(high>mid+1)
            quicksort1(vec,mid+1,high);
    }
}

/**ʹ��ջ�ķǵݹ��������**/
template<typename Comparable>
void quicksort2(vector<Comparable> &vec,int low,int high){
    //������
    if(vec.size()==0||low<0||high<0||low>high){
        invalidInputNRecursive=true;
        return ;
    }
    if(low==high)
        return ;

    stack<int> st;
    st.push(low);
    st.push(high);
    while(!st.empty()){
        int last=st.top();
        st.pop();
        int first=st.top();
        st.pop();
        int mid=partition(vec,first,last);
        if(first<mid-1){
            st.push(first);
            st.push(mid-1);
        }
        if(last>mid+1){
            st.push(mid+1);
            st.push(last);
        }
    }
}

int main(){
//    int len=1000000;
    vector<int> vec={49,65,78,23,12,-2,5,10,80};
//    for(int i=0;i<len;i++)
//        vec.push_back(rand());

    vector<int> vec1(vec);

    clock_t t1=clock();
    quicksort1(vec,0,8);
    clock_t t2=clock();
    cout<<"recurcive  "<<1.0*(t2-t1)/CLOCKS_PER_SEC<<endl;

    //���´���˳��
   // random_shuffle(vec.begin(),vec.end());

    t1=clock();
    quicksort2(vec1,0,8);
    t2=clock();
    cout<<"none recurcive  "<<1.0*(t2-t1)/CLOCKS_PER_SEC<<endl;

    for(auto &i:vec)
        cout<<i<<" ";
    cout<<endl;
    for(auto &i:vec1)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
