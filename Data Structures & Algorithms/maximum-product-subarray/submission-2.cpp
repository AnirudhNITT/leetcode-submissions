class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size=nums.size();
        vector<int>dp(size);
        int max_num=nums[0];
        int min_num=nums[0];
        int curr=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<size;i++){
            int temp_max=max_num;
            int temp_min=min_num;
            max_num=max(nums[i],max(temp_max*nums[i],temp_min*nums[i]));
            min_num=min(nums[i],min(temp_min*nums[i],temp_max*nums[i]));
            dp[i]=max_num;
            curr=max(dp[i],curr);
        }
        return curr;
    }
};
