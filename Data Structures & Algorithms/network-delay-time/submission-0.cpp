class Solution {
public:

    vector<vector<pair<int,int>>> build_adj(vector<vector<int>> &times,int n){
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        return adj;
    }

    vector<int> dijkstra(vector<vector<pair<int,int>>> &adj,int k){
        int size=adj.size();
        vector<int> dist(size,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(d>dist[node])continue;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                
                if(dist[node]+wt<dist[adjNode]){
                    dist[adjNode]=dist[node]+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj=build_adj(times,n);
        vector<int> dist=dijkstra(adj,k);
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};