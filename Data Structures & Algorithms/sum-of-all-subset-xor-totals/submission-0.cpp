class Solution {
public:
    int ans=0;
    void backtrack(vector<int>& nums,int idx, int curr_xor){
        if(idx==nums.size()){
            ans+=curr_xor;
            return;
        }
        backtrack(nums,idx+1,curr_xor^nums[idx]);
        backtrack(nums,idx+1,curr_xor);
    }
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums,0,0);
        return ans;
    }
};