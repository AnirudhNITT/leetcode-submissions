class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>solns;
        unordered_map<int,int>freq;
        for (int x : nums) {
            freq[x]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &p :freq){
            pq.push({p.second,p.first});
        }
        for(int i=0;i<k;i++){
            solns.emplace_back(pq.top().second);
            pq.pop();
        }
    return solns;
        
    }
};
