class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int xor_all = nums.size();  
    for (int i = 0; i < nums.size(); i++) {
        xor_all ^= i ^ nums[i];
    }
    return xor_all;
}
};
