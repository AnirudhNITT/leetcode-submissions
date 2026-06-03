class Solution {
public:
    static bool comp1(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    
    struct comp2{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first)return a.second>b.second;
            return a.first>b.first;
        }
    };

    vector<int> getOrder(vector<vector<int>>&tasks) {
        vector<vector<int>>new_vec;
        int curr_idx=0;
        for(auto it:tasks){
            new_vec.push_back({it[0],it[1],curr_idx});
            curr_idx++;
        }

        vector<int>soln;
        sort(new_vec.begin(),new_vec.end(),comp1);

        priority_queue<pair<int,int>,vector<pair<int,int>>,comp2>pq;
        long long curr_time=0;
        curr_idx=0;
        while(curr_idx<new_vec.size() || !pq.empty()){
            if(pq.empty() && curr_time<new_vec[curr_idx][0]){
                curr_time=new_vec[curr_idx][0];
            }
            while(curr_idx<new_vec.size() && new_vec[curr_idx][0]<=curr_time){
                pq.push({new_vec[curr_idx][1],new_vec[curr_idx][2]});
                curr_idx++;
            }
            int top=pq.top().first;
            int indx=pq.top().second;
            pq.pop();
            curr_time+=top;
            soln.push_back(indx);
        }
        return soln;
    }
};