#include <iostream>
#include<vector>

using namespace std;

bool split(vector<int> &input_array){
    if(input_array.size()<7)
        return false;
    int first=1,last=input_array.size()-1;
    int left_sum=input_array[0],right_sum=0;
    vector<int> sum;
    vector<int> first_tag;
    vector<int> last_tag;
    while(first<=last){
        if(left_sum<right_sum){
            left_sum+=input_array[first];
            ++first;
        }
        else if(left_sum>right_sum){
            right_sum+=input_array[last];
            --last;
        }
        else if(left_sum==right_sum){
            first_tag.push_back(first);
            last_tag.push_back(last);
            sum.push_back(left_sum);
            left_sum+=input_array[first];
            ++first;
            right_sum+=input_array[last];
            --last;
        }
    }

    left_sum=right_sum=0;
    for(vector<int>::size_type i=0;i<sum.size();++i){
        first=first_tag[i]+1;
        last=last_tag[i]-1;
        left_sum+=input_array[first++];
        while(first<=last){
            if(left_sum<right_sum){
                left_sum+=input_array[first];
                ++first;
            }
            else if(left_sum>right_sum){
                right_sum+=input_array[last];
                --last;
            }
            else if(left_sum==right_sum){
                if((first==last)&&(left_sum==sum[i]))
                    return true;
                else{
                    left_sum+=input_array[first];
                    ++first;
                    right_sum+=input_array[last];
                    --last;
                }
            }
        }
    }
    return false;
}
int main()
{
//    int num;//数组总数
//    int value;//数组中元素值
    vector<int> input_array;

    input_array.push_back(2);
    input_array.push_back(5);
    input_array.push_back(1);
    input_array.push_back(1);
    input_array.push_back(1);
    input_array.push_back(1);
    input_array.push_back(4);
    input_array.push_back(1);
   input_array.push_back(7);
   input_array.push_back(3);
   input_array.push_back(7);
//    input_array.push_back(10);


    bool result=split(input_array);
    cout<<result<<endl;
//    while(cin>>num){
//        input_array.clear();
//        while(num--){
//            cin>>value;
//            input_array.push_back(value);
//        }
//        cout<<"size:"<<input_array.size()<<endl;
//        cout<<split(input_array)<<endl;
//    }
    return 0;
}
