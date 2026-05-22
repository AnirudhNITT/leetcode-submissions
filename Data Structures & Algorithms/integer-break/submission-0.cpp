class Solution {
public:
    int integerBreak(int n) {        
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int j=2;j<=n;j++){
            int max_product = 0;
            for(int i=0;i<=j;i++){
                int max_left=max(i,dp[i]);
                int max_right=max(j-i,dp[j-i]);
                max_product=max(max_product,max_left*max_right);
                dp[j]=max_product;
            }
            
        }
    return dp[n];
    }
};