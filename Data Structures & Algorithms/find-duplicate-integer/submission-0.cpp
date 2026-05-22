class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool>hash;
        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]]==true){
                return nums[i];
            }
            else{
                hash[nums[i]]=true;
            }
        }
    }
};
