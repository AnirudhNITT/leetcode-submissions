class Solution {
public:
    vector<vector<int>>soln;
    vector<int>path;
    void backtrack(vector<int>&nums,int i){
        soln.push_back(path);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])continue;
            path.push_back(nums[j]);
            backtrack(nums,j+1);
            path.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return soln;
    }
};
