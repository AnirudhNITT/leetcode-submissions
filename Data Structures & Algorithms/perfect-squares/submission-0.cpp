class Solution {
public:
    
    int numSquares(int n) {
        vector<int>dp(n+1,n);
        for(int i=0;i<n+1;i++){
            if(i*i>n)break;
            dp[i*i]=1;
        }
       for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(1+dp[i-j*j],dp[i]);
            }
       }
       return dp[n];
        
    }
};