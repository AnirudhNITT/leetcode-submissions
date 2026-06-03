class Solution {
public:
    bool backtrack(vector<int> &nums,vector<int> &subset,int target_sum,int curr_idx){
        if(curr_idx==nums.size()){
            for(int i=1;i<subset.size();i++){
                if(!(subset[i]==subset[i-1]))return false;
            }
            return true;
        }
        for(int i=0;i<subset.size();i++){
            if(subset[i]+nums[curr_idx]>target_sum)continue;
            subset[i]+=nums[curr_idx];
            if(backtrack(nums,subset,target_sum,curr_idx+1))return true;
            subset[i]-=nums[curr_idx];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int target_sum=0;
        for(auto it : nums){
            target_sum+=it;
        }
        if(target_sum%k!=0)return false;
        vector<int>subset(k,0);
        return (backtrack(nums,subset,target_sum/k,0));
    }
};