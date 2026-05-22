class Solution {
public:
    vector<vector<int>>soln;
    vector<int>path;
    void backtrack(vector<int>&nums,int target,int i){
        int sum=0;
        for(int j=0;j<path.size();j++){
            sum+=path[j];
        }
        if(sum>=target){
            if(sum>target){
                return;
            }
            else{
                soln.push_back(path);
            }
        }
        for (int j=i;j<nums.size();j++){
            path.push_back(nums[j]);
            backtrack(nums,target,j);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        backtrack(nums,target,0);
        return soln;
    }
};
