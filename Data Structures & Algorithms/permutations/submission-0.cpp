class Solution {
public:
    vector<vector<int>>soln;
    vector<int>path;
    vector<bool>used;
    void backtrack(vector<int>&nums){
        if(path.size()==nums.size()){
            soln.push_back(path);
            return;
        }
        for (int j=0;j<nums.size();j++){
            if (used[j]) continue;
            used[j] = true;
            path.push_back(nums[j]);
            backtrack(nums);
            path.pop_back();
            used[j]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        backtrack(nums);
        return soln;
    }
};
