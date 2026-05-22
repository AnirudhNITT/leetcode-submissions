class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=nums.size()-1;
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]+j>=goal){
                goal=j;
            }
        }
        return (goal==0);
    }
};
