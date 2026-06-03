class Solution {
public:
    static bool custom_comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>&trips,int capacity){
        sort(trips.begin(),trips.end(),custom_comp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int curr_capacity=0;
        int curr_idx=0;
        int curr_time=0;
        while(curr_idx<trips.size()){
            if(curr_time<trips[curr_idx][1]){
                curr_time=trips[curr_idx][1];
                while(!pq.empty()&&pq.top().first<=curr_time){
                    curr_capacity-=pq.top().second;
                    pq.pop();
                }
            }
            pq.push({trips[curr_idx][2],trips[curr_idx][0]});
            curr_capacity+=trips[curr_idx][0];
            if(curr_capacity>capacity)return false;
            curr_idx++;
        }
        return true;
    }
};