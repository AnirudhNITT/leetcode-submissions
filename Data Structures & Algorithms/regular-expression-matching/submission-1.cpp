class Solution {
public:
    bool dfs(int i,int j,string a,string b,map<pair<int,int>,bool>&dp){
        if (j == b.size()) return i == a.size();
        if(dp.find({i,j})!=dp.end())return dp[{i,j}];
        bool match = (i < a.size() && (a[i] == b[j] || b[j] == '.'));
        if(j+1<b.size() && b[j+1]=='*'){
            bool flag=false;
            if(match){
                if(dfs(i+1,j,a,b,dp))flag=true;
            }
            if(dfs(i,j+2,a,b,dp))flag=true;
            if(flag)if(flag) return dp[{i,j}] = true;
        }
        if(match)return dp[{i,j}] = dfs(i+1,j+1,a,b,dp);
        else return dp[{i,j}]=false;
        }
    bool isMatch(string s, string p) {
        map<pair<int,int>,bool>dp;
        return dfs(0,0,s,p,dp);
    }
};
