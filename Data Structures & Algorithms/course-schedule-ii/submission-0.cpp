class Solution {
public:
    vector<vector<bool>> adja(int num,vector<vector<int>>&preq){
        vector<vector<bool>>adj(num,vector<bool>(num,true));
        for(int i=0;i<num;i++){
            adj[i][i]=true;
        }
        for(auto it :preq){
            adj[it[0]][it[1]]=false;
        }
        return adj;
    }
    bool dfs(int start,vector<int> &visit,stack<int> &st,vector<vector<bool>>&adj){
        if(visit[start]==1)return true;
        if(visit[start]==2)return false;
        visit[start]=1;
        for(int i=0;i<visit.size();i++){
            if(!adj[start][i]){
                if (dfs(i,visit,st,adj)){
                    return true;
                }
            }
        }
        visit[start]=2;
        st.push(start);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>>adj=adja(numCourses,prerequisites);
        stack<int>st;
        vector<int>visit(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(dfs(i,visit,st,adj)){
                return {};
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
