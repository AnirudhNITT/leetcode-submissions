class Solution {
public:
    vector<vector<int>> adjacency(vector<vector<int>> &edges , int n){
        vector<vector<int>>matrix(n,vector<int>(n,0));
        for(auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            matrix[u][v]=1;
            matrix[v][u]=1;
        }
        return matrix;
    }
    void dfs(vector<vector<int>> &adj,vector<bool> &visit,int start){
        visit[start]=true;
        for(int v=0;v<adj[0].size();v++){
            if(adj[start][v]==0)continue;
            if(!visit[v]){
                dfs(adj,visit,v);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector<bool>visited(n,false);
        vector<bool>checker(n,true);
        vector<vector<int>>adj= adjacency(edges,n);
        while(!(visited==checker)){
            for(int v=0;v<n;v++){
                if(!visited[v]){
                count++;
                dfs(adj,visited,v);
                }
            }
        }
        return count; 
    }
    
};
