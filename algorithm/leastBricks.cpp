#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<map>

using namespace std;

int leastBricks(vector <vector<int>> matrix) {
    int leastBrick=0;
    map<int,int> resultMap;
    for(vector<vector<int>>::size_type i=0;i!=matrix.size();++i){
        int curr=0;
        for(vector<int>::size_type j=0;j!=matrix[i].size();++j){
            curr+=matrix[i][j];
            ++resultMap[curr];
        }
    }
    int maxVal=INT_MIN;
    map<int,int>::iterator iter=resultMap.end();
    --iter;
    for(map<int,int>::iterator it=resultMap.begin();it!=iter;++it){
        if((*it).second>maxVal)
            maxVal=(*it).second;
    }
    leastBrick=matrix.size()-maxVal;
    return leastBrick;
}

int main() {
    int cols=0;
    cin>>cols;
    vector<vector<int>> matrix(cols);
    int currCol=0;
    int width=0;
    int endflag=0;
    while(currCol<cols&&cin>>width){
        if(width!=endflag){
            matrix[currCol].push_back(width);
        }
        else ++currCol;
    }
    int leastBrick = leastBricks(matrix);
    cout<<leastBrick<<endl;

    return 0;

}
