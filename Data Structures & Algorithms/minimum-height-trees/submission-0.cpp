class Solution {
public:
    unordered_map<int,vector<int>> build_adj(vector<vector<int>>& edges,int n){
        unordered_map<int,vector<int>> mp;
        for(auto it : edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        return mp;
    }
    int dfs(int curr,int parent,unordered_map<int,vector<int>>& adj){
        int curr_ht=0;
        for(auto nei : adj[curr]){
            if(nei==parent) continue;
            curr_ht=max(curr_ht,1+dfs(nei,curr,adj));
        }
        return curr_ht;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        auto adj=build_adj(edges,n);
        for(int i=0;i<n;i++){
            pq.push({dfs(i,-1,adj),i});
        }
        vector<int> soln;
        int min_ht=pq.top().first;
        while(!pq.empty() && pq.top().first==min_ht){
            soln.push_back(pq.top().second);
            pq.pop();
        }
        return soln;
    }
};