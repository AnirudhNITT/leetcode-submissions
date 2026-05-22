class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_find=nums[0];
        for(int i=1;i<nums.size();i++){
            xor_find=xor_find^nums[i];
        }
        return xor_find;
    }
};
