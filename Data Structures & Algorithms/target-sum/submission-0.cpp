class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(nums.begin(), nums.end(), 0);
    
        // invalid cases
        if ((target + S) % 2 != 0 || abs(target) > S)
        return 0;
    
        int P = (target + S) / 2;
    
        vector<int> dp(P + 1, 0);
        dp[0] = 1;
    
        for (int num : nums) {
            for (int j = P; j >= num; j--) {
            dp[j] += dp[j - num];
            }
            }
    
         return dp[P];
    }
};
