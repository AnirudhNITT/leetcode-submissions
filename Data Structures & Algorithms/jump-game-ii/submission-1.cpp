class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0,end=0,far=0;
        for(int i=0;i<nums.size()-1;i++){
            far=max(far,nums[i]+i);
            if(i==end){
                jump++;
                end=far;
            }
        }
        return jump;
    }
};
