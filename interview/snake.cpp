#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_stride(const vector<pair<int,int> > &numberOfW){

	int result=0;
	int flag=true;//表明方向向右
	int col=0;//当前所在列数
	for(vector<pair<int,int> >::size_type i=0;i!=numberOfW.size()-1;++i){
        if(flag){
            int right=max(numberOfW[i].second,numberOfW[i+1].second);
            if(right==-1){
                result+=1;
                flag=false;
                continue;
            }
            else if(right<col){
                result+=1;
                flag=false;
                continue;
            }
            else{
                result+=right-col+1;
                col=right;
                flag=false;
            }
        }
        else{
            int left=0;
            if(numberOfW[i].first==-1&&numberOfW[i+1].first==-1){
                left=-1;
            }
            else if(numberOfW[i].first!=-1&&numberOfW[i+1].first!=-1){
                left=min(numberOfW[i].first,numberOfW[i+1].first);
            }
            else if(numberOfW[i].first!=-1){
                left=numberOfW[i].first;
            }
            else{
                left=numberOfW[i+1].first;
            }
            if(left==-1){
                result+=1;
                flag=true;
                continue;
            }
            else if(left>col){
                result+=1;
                flag=true;
                continue;
            }
            else{
                result+=col-left+1;
                col=left;
                flag=true;
            }
        }
	}
	if(flag){
        int right=numberOfW[numberOfW.size()-1].second;
        if(right==-1)
            --result;
        else if(col!=right)
            result+=right-col;
	}
	else{
        int left=numberOfW[numberOfW.size()-1].first;
        if(left==-1)
            --result;
        else if(col!=left){
            result+=col-left;
        }
	}
	return result;
}

int main(){
	vector<pair<int,int> > numberOfW;
	int row;
	int col;
	cin>>row>>col;
	for(int i = 0; i != row;++i){
		int first=-1;
		int last=-1;
		bool flag=true;
		for(int j=0;j!=col;++j){
			char ch;
			cin>>ch;
			if(ch=='W'&&flag){
				first=last=j;
				flag=false;
			}
			else if(ch=='W'&&!flag) last=j;
		}
		numberOfW.push_back(make_pair(first,last));
	}

    int result=max_stride(numberOfW);
	cout<<"result:"<<result<<endl;

	return 0;
}
