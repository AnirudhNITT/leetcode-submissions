class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0;
        unordered_set<int>mp;
        for(int r=0;r<nums.size();r++){
            if(r-l>k){
                mp.erase(nums[l]);
                l++;
            }
            if(mp.find(nums[r])!=mp.end())return true;
            mp.insert(nums[r]);
        }
        return false;
    }
};