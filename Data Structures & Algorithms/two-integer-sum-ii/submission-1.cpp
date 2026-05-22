class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>soln;
        int start_count=1;
        int end_count=nums.size();
        auto start=nums.begin();
        auto end =nums.end()-1;
        while (start<end){
            if (*start+*end==target){
                soln.emplace_back(start_count);
                soln.emplace_back(end_count);
                return soln;
            }
            else if (*start + *end>target){
                end--;
                end_count--;
            }
            else if (*start + *end<target){
                start++;
                start_count++;
            }
        }
        }
};
