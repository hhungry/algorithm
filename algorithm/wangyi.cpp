#include<iostream>
#include<vector>
#include<functional>

using namespace std;

int Knapsack(vector<int>& value, int capacity){
    int result = -1;
    int sum = 0;
    for(size_t i = 0; i != value.size(); ++i){
        sum += value[i];
    }
    if(sum < capacity) return result;

	vector<int> status(capacity+1, 0);
	for(int i = 0; i != value.size(); ++i){
		for(int j = capacity; j > 0; --j){
			if(j >= value[i]){
			    int tempValue;
                if(status[j - value[i]] == 0) tempValue = value[i];
				else tempValue = status[j-value[i] ] * value[i];
				status[j] = status[j] > tempValue ? status[j] : tempValue;
			}
			else break;
		}
	}


	return status[capacity];
}

int main(){
    int n;
    cin>>n;
    vector<int> iVec(n);
    for(size_t i = 0; i != n; ++i){
        cin>>iVec[i];
    }
    int m;
    cin>>m;
    cout<<Knapsack(iVec, m)<<endl;
    return 0;
}


#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<assert.h>
#include<algorithm>
using namespace std;
bool compare(const string &str1,const string &str2){
    bool rst;
    string tmp1=str1+str2;
    string tmp2=str2+str1;
    if(tmp1>=tmp2)
        rst=true;
    else rst=false;
    return rst;
}

string printMaxNumber(vector<int> &vec){
    if(vec.size()==0)
        return string();
    stringstream ss;
    string str;
    vector<string> svec;
    for(decltype(vec.size()) i=0;i<vec.size();++i){
        ss<<vec[i];
        ss>>str;
        svec.push_back(str);
        ss.clear();
        ss.str("");
    }

    sort(svec.begin(),svec.end(),compare);
    string rst;
    for(auto ele:svec)
        rst+=ele;
    return rst;

}
int main()
{
    int n=0;
    vector<int> vec;
    while(cin>>n)
        vec.push_back(n);
    assert(vec.size()!=0);
    string maxValue=printMaxNumber(vec);
    cout<<maxValue<<endl;
}

#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

struct Point{
    int x;
    int y;
    Point(){}
};

int main() {
    int len;
    cin>>len;
    vector<Point> points(len);
    for(size_t i = 0; i != len; ++i){
        cin>>points[i].x>>points[i].y;
    }

    if (len <= 2)
        return len;

    map<double, int> m;
    int num= INT_MIN;
    int count = 0;
    for (int i = 0; i < len-1; ++i)
    {
        m.clear();
        int same = 0;
        m[(double)INT_MIN] = 1;
        for (int j = i + 1; j < len; ++j)
        {
            if (points[i].x == points[j].x&&points[i].y == points[j].y)//若亮点相同，则same++
            {
                same++;
                continue;
            }
            double rate;
            if (points[j].x - points[i].x == 0)//若斜率无限大，则将值设为INT_MAX
            {
                rate = INT_MAX;
            }
            else
            {
                rate = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
            }
            if (m.find(rate) != m.end())
                m[rate] += 1;
            else
                m[rate] = 2;
        }
        for (map<double, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            num = it->second + same > num ? it->second + same : num;
        }
    }
    cout<<num<<endl;
    return 0;
}

#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    string input;
    getline(cin, input);
    stack<char> cStack;
    for(size_t i = 0; i != input.size(); ++i){
        if(isalpha(input[i])) continue;
        if(input[i] == '(' || input[i] == '{' || input[i] == '['){
            cStack.push(input[i]);
        }
        else if(input[i] == ')' && cStack.top() == '(') cStack.pop();
        else if(input[i] == '}' && cStack.top() == '{') cStack.pop();
        else if(input[i] == ']' && cStack.top() == '[') cStack.pop();
        else continue;
    }
    if(cStack.size() == 0) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}




















