class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len=nums.size()+1;
        int l=0;
        int curr_sum=0;
        for(int r=0;r<nums.size();r++){
            curr_sum+=nums[r];
            while(r>=l && curr_sum>=target){
                min_len=min(min_len,r-l+1);
                curr_sum-=nums[l];                
                l++;
                
            }
        }
    return (min_len==nums.size()+1)?0:min_len;
    }
};