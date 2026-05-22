class Solution {
public:
    vector<vector<int>> buildadj(vector<vector<int>>& points){
        int size=points.size();
        vector<vector<int>>adj(size,vector<int>(size,0));
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                adj[i][j]=(abs(points[i][0]-points[j][0])+abs((points[i][1]-points[j][1])));
            }
        }
        return adj;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>adj=buildadj(points);
        int n=adj.size();
        vector<bool>visit(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int curr_sum=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int wt=it.first;
            int node=it.second;
            pq.pop();
            if(visit[node])continue;
            curr_sum+=wt;
            visit[node]=true;
            for(int i=0;i<n;i++){
                if(adj[node][i]==0 || visit[i])continue;
                else(pq.push({adj[node][i],i}));
            }
            
        }
        return curr_sum;
    }
};
