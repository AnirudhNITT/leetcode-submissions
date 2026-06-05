class Solution {
public:
    unordered_map<int,vector<int>> build_adj(vector<vector<int>>&pre,int num){
        unordered_map<int,vector<int>>mp;
        for(auto it:pre){
            if(mp.find(it[0])==mp.end())mp[it[0]]={it[1]};
            else mp[it[0]].push_back(it[1]);
        }
        return mp;
    }
    bool dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int curr,int find){
        if(adj.find(curr)==adj.end())return false;
        auto vec=adj[curr];
        for(auto it :vec){
            if(!vis[it]){
                vis[it]=true;
                if(it==find)return true;
                if(dfs(adj,vis,it,find))return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        auto adj=build_adj(prerequisites,numCourses);
        vector<bool>soln;
        for(auto it:queries){
            vector<bool>vis(numCourses,false);
            soln.push_back(dfs(adj,vis,it[0],it[1]));
        }
        return soln;
    }
};