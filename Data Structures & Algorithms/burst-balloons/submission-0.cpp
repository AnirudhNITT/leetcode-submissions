class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int>arr;
        arr.push_back(1);
        for(auto x:nums){
            if(x>0)arr.push_back(x);
        }
        arr.push_back(1);
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=2;len<n;len++){
            for(int l=0;l+len<n;l++){
                int r=l+len;
                for(int k=l+1;k<r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+arr[l]*arr[k]*arr[r]);
                }
            }
        }
        return dp[0][n-1];
    }
};