class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        int curr_sum=0;
        mp[curr_sum]++;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            int diff=curr_sum-k;
            ans+=(mp.find(diff)!=mp.end())?mp[diff]:0;
            mp[curr_sum]++;
        }
        return ans;
    }
};