class Solution {
public:
    unordered_map<char,vector<char>> build_adj(string order){
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<order.size()-1;i++){
            for(int j=i+1;j<order.size();j++){
                adj[order[i]].push_back(order[j]);
            }
        }
        adj[order[order.size()-1]]={};
        return adj;
    }
    bool check(string s1,string s2,unordered_map<char,vector<char>>&adj){
        int len=min(s1.size(),s2.size());
        for(int i=0;i<len;i++){
            if(s1[i]==s2[i])continue;
            else{
                bool flag=false;
                for(auto val :adj[s1[i]]){
                    if(val==s2[i])flag=true;
                }
                if(!flag)return false;
                return true;
            }
        }
        if(s1.size()>s2.size())return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,vector<char>>adj=build_adj(order);
        for(int i=0;i<words.size()-1;i++){
            if(!check(words[i],words[i+1],adj))return false;
        }
        return true;
    }
};