class Solution {
public:
    vector<vector<int>>soln;
    vector<int>path;
    void backtrack(vector<int>&nums,int i){
        soln.push_back(path);

        for(i;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(nums,i+1);
            path.pop_back();

        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return soln;
        
    }
};
