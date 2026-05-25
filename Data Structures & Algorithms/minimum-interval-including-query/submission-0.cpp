class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int len(vector<int>&q){
        return q[1]-q[0]+1;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<int>soln(queries.size());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq_q;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<queries.size();i++){
            pq_q.push({queries[i],i});
        }
        int iter=0;
        while(!pq_q.empty()){
            auto top=pq_q.top();
            pq_q.pop();
            int val=top.first;
            int indice=top.second;
            while(iter<intervals.size() && intervals[iter][0]<=val){
                pq.push({len(intervals[iter]),intervals[iter][1]});
                iter++;
            }
            while(!pq.empty() && pq.top().second<val){
                pq.pop();
            }
            if(pq.empty()) soln[indice]=-1;
            else soln[indice]=pq.top().first;
        }
        return soln;
    }
};