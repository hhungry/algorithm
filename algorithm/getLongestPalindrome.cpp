class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(A.size()==0||A.size()!=n)
            return 0;
        bool **dp=new bool*[n];
        for(int i=0;i<n;++i){
            dp[i]=new bool[n];
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j)
                    dp[i][j]=true;
                else dp[i][j]=false;
            }
        }
      
        int maxlen=1;
    
        
        for(int k=2;k<=n;++k){
            for(int i=0;i<n+1-k;++i){
                if(k==2&&A[i]==A[i+k-1]){
                	dp[i][i+k-1]=true;
                	if(k>maxlen){
                    	maxlen=k;
                	}
                }
                else if(A[i]==A[i+k-1]&&dp[i+1][i+k-2]){
                    dp[i][i+k-1]=true;
                    if(k>maxlen){
                    	maxlen=k;
                	}
                }
                 
            }
        }
        return maxlen;
        
    }
};
