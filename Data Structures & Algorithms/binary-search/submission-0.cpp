class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto start=nums.begin();
        auto end=nums.end()-1;
        while(start <= end){
            if (*start==target){
                return start-nums.begin();
            }
            else if(*end==target){
                return end-nums.begin();
            } 
            start++;
            end--;
        }
        return -1;
    }
};
