class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(auto it :nums){
            int curr=it;
            for(auto it :nums){
                curr=curr^it;
            }
            if(curr==0)return it;
        }
    }
};
