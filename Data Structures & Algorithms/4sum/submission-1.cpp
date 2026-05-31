class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int l_indx=0;l_indx<nums.size()-3;l_indx++){
            for(int r_indx=l_indx+1;r_indx<nums.size()-2;r_indx++){
                int l=r_indx+1;
                int r=nums.size()-1;
                if(l_indx>0 && nums[l_indx]==nums[l_indx-1]) continue;
                if(r_indx>l_indx+1 && nums[r_indx]==nums[r_indx-1]) continue;
                while(l<r){
                    long long curr_sum=(long long)nums[l_indx]+nums[r_indx]+nums[l]+nums[r];
                    if(curr_sum==target){
                        ans.push_back({nums[l_indx],nums[l],nums[r],nums[r_indx]});
                        l++;
                        r--;
                        while(l<r && nums[l]==nums[l-1]) l++;
                        while(l<r && nums[r]==nums[r+1]) r--;

                        curr_sum=0;
                    }
                    else if(curr_sum<target){
                        l++;
                    }
                    else if(curr_sum>target){
                        r--;
                    }
                    
                }
            }
        }
        return ans;
    }
};