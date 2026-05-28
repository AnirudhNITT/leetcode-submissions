class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int replace_index=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val)count++;
        }
        for(int i=0;i<nums.size()-count;i++){
            while(nums[replace_index]==val)replace_index--;
            if(nums[i]==val){
                int temp=nums[i];
                nums[i]=nums[replace_index];
                nums[replace_index]=nums[i];
                replace_index--;
            }
        }
        return nums.size()-count;
    }
};