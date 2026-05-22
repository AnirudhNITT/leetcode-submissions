class Solution {
public:
    bool isCycle(vector<vector<int>>&adj,vector<bool>&visited,vector<bool> &ogvisit,int child){
        visited[child]=true;
        ogvisit[child]=true;
        for(int i=0;i<adj.size();i++){
            if(adj[child][i]==1){
                if(!ogvisit[i]){
                     if(isCycle(adj,visited,ogvisit,i))
                     return true;
                }
                else if(visited[i]==true){
                    return true;
                }
            }
         
        }
        visited[child]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>>adj(numCourses,vector<int>(numCourses,0));
        vector<bool>visited(numCourses,false);
        vector<bool>ogvisit(numCourses,false);
        for(auto &edge : edges){
            adj[edge[0]][edge[1]]=1;
        }
        for(int i=0;i<numCourses;i++){
            if(isCycle(adj,visited,ogvisit,i))return false;
        }
     return true;
    }
};
