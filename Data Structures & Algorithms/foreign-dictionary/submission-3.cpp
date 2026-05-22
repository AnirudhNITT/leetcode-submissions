class Solution {
public: 
    unordered_map<char,vector<char>> build(vector<string>&words){
        unordered_map<char,vector<char>>adj;
        for(auto &word:words){
            for(char c:word) adj[c];
        }
        
        for(int i=0;i<words.size()-1;i++){
            string smaller=words[i];
            string bigger=words[i+1];
            int len=min(smaller.size(),bigger.size());
            bool found=false;
            for(int k=0;k<len;k++){
                if(smaller[k]==bigger[k]) continue;
                else{
                    adj[smaller[k]].push_back(bigger[k]);
                    found=true;
                    break;
                }
            }
            if(!found && smaller.size()>bigger.size())return {};
        }
        return adj;
    }
    bool dfs(char node,unordered_map<char,vector<char>>&adj,unordered_map<char,int>&vis,stack<char>&st){
        if(vis[node]==1)return true;
        if(vis[node]==2)return false;
        vis[node]=1;
        for(auto it :adj[node]){
            if(dfs(it,adj,vis,st))return true;
        }
        vis[node]=2;
        st.push(node);
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>>adj=build(words);
        unordered_map<char,int>vis;
        for(auto it:adj){
            if(vis.find(it.first)==vis.end())vis[it.first]=0;
        }
        stack<char>st;
        for(auto &it:adj){
            if(vis[it.first]==0){
                if(dfs(it.first,adj,vis,st))return "";
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    return ans;
    }
};
