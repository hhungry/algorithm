class Palindrome {
public:
    //dp方法
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
    
    
    //中心扩展法
     int getLongestPalindrome(string A, int n) {
        // write code here
        if(A.size()==0||A.size()!=n)
            return 0;
        int maxlen=0;
        int tmp=0;
        for(int i=0;i<n;++i){
            for(int j=0;(i-j>=0)&&(i+j)<n;++j){
                if(A[i-j]==A[i+j]){
                    tmp=2*j+1;
                }
                else break;
            }
            if(tmp>maxlen)
                maxlen=tmp;
            for(int j=0;(i-j>=0)&&(i+j+1)<n;++j){
            	if(A[i-j]==A[i+j+1]){
                    tmp=2*j+2;
                }
                else break;
            }
            if(tmp>maxlen)
                maxlen=tmp;
        }
        return maxlen;
    }
};
