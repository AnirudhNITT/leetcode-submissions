class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int>st;
        int max_size=0;
        for(int i=0;i<nums.size();i++){
            if(st.empty()||nums[i]-st.top()==1){
                st.push(nums[i]);
            }
            else if(nums[i]==st.top()){
                continue;
            }
            else{
                if(max_size<st.size()){
                    max_size=st.size();
                }
                st = stack<int>();
                st.push(nums[i]);

            }
        }
        max_size = max(max_size, (int)st.size());
        return max_size;
    }
};
