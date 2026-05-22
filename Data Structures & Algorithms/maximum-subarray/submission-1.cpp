class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0;
        int best=nums[0];
        for(int i=0;i<nums.size();i++){
            curr_sum=(curr_sum>0)?curr_sum:0;
            curr_sum+=nums[i];
            best=(best>curr_sum)?best:curr_sum;
        }
    return best;
    }
};
