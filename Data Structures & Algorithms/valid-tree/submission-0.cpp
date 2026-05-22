class Solution {
public: 
    vector<vector<int>> adjacency(vector<vector<int>>& edges,int n){
        vector<vector<int>> matrix(n,vector<int>(n,0));
        for(vector<int> &edge : edges){
            matrix[edge[0]][edge[1]]=1;
            matrix[edge[1]][edge[0]]=1;
        }
        return matrix;
    } 
    bool is_cycle(int u,int parent,vector<vector<int>>& adj , vector<bool>& visited ){
        visited[u]=true;
   
        for(int v=0; v<adj[0].size();v++){
            if(adj[u][v]==1&& !visited[v]){
                if(is_cycle(v,u,adj,visited)){
                    return true;
                }
            }
            else if(adj[u][v]==1 && v!=parent){
                return true;
            }
        }    
        return false;
    }
    
    vector<bool> dfs(int u,vector<bool>& visited,vector<vector<int>>& adj){
        visited[u]=true;
        for(int v=0;v<adj.size();v++){
            if(adj[u][v]==1 and !visited[v]){
               dfs(v,visited,adj);
            }
        }
        return visited;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj=adjacency(edges,n);
        vector<bool>visited(n,false);
        vector<bool>visitedcheck(n,true);
        if(visitedcheck==dfs(0,visited,adj)){
            vector<bool>visited1(n,false);
            if(!(is_cycle(0,-1,adj,visited1))){
                return true ;
            }
        }
        return false;
    }
};
