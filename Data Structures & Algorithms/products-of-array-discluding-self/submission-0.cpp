class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        unordered_map<int,int>hash1;
        unordered_map<int,int>hash2;
        hash1[0]=1;
        hash2[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            hash1[i]=hash1[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            hash2[i]=hash2[i+1]*nums[i+1];
        }
        vector<int>soln;
        for(int i=0;i<nums.size();i++){
            soln.push_back(hash1[i]*hash2[i]);
        }
       return soln;
       
    }
};
