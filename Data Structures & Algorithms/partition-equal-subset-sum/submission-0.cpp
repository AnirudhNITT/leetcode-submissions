class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0)return false;
        target=target/2;
        vector<bool>dp(target+1);
        dp[0]=true;
        for(auto num :nums){
            for(int s=target;s>=num;s--){
                dp[s]=dp[s]||dp[s-num];
            }
            if(dp[target])return true;
        }
        return dp[target];
    }
};
