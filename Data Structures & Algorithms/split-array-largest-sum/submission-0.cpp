class Solution {
public:
    bool is_psbl(vector<int>& nums,int k,int val){
        int cnt=1;
        int sum=0;

        for(auto it:nums){
            if(sum+it<=val){
                sum+=it;
            }
            else{
                cnt++;
                sum=it;
            }
        }

        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=0;

        for(auto it:nums){
            l=max(l,it);
            r+=it;
        }

        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(is_psbl(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};