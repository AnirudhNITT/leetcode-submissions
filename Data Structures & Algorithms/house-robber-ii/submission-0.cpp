class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = l; i <= r; i++) {
            int take = prev2 + nums[i];
            int notTake = prev1;
            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int case1 = robLinear(nums, 0, n - 2);

        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
