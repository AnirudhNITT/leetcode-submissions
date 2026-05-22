class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=k-1;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        vector<bool>in_window(nums.size(),false);
        for(int i=0;i<=r;i++){
            pq.push({nums[i],i});
            in_window[i]=true;
        }
        vector<int>soln;
        while(r<nums.size()){
            while(true){
                auto it=pq.top();
                int val=it.first;
                int pos=it.second;
                if(in_window[pos]){
                    soln.push_back(val);
                    break;
                }
                pq.pop();
            }
           
            in_window[l++]=false;
            r++;
            if(r<nums.size()){
                pq.push({nums[r],r});
                in_window[r]=true;
            }
        }
        return soln;
    }
};
