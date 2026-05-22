class Solution {
public:
    vector<vector<int>>soln;
    vector<int>path;
    void backtrack(vector<int> &nums, int i,int k){
        if(path.size()==k){
            soln.push_back(path);
            return;
        }
        for(i;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(nums,i+1,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        backtrack(nums,0,k);
        return soln;

    }
};