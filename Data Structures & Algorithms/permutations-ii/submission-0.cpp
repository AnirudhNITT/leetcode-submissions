class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int> nums,int curr_idx){
        if(curr_idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>seen;
        for(int i=curr_idx;i<nums.size();i++){
            if(seen.count(nums[i]))continue;
            seen.insert(nums[i]);
            swap(nums[i],nums[curr_idx]);
            backtrack(nums,curr_idx+1);
            swap(nums[i],nums[curr_idx]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums,0);
        return ans;
    }
};