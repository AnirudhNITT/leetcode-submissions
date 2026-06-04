class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_sum=0;
        int best_sum=nums[0];
        int total_sum=0;
        int worst_sum=nums[0];
        int curr_worst_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum+=nums[i];
            curr_sum = max(nums[i], curr_sum + nums[i]);
            best_sum = max(best_sum, curr_sum);
            curr_worst_sum = min(nums[i], curr_worst_sum + nums[i]);
            worst_sum = min(worst_sum, curr_worst_sum);
        }
        if(best_sum<0)return best_sum;
        return max(best_sum,total_sum-worst_sum);
    }
};