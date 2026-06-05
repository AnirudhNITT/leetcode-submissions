class Solution {
public:
    vector<vector<int>> dp;
    vector<int> piles;
    int dfs(int l,int r,bool al_turn){
        if(l==r){
            if(al_turn)return piles[l];
            return -piles[l];
        }
        if(dp[l][r]!=-1)return dp[l][r];
        if(al_turn){
            int case_1=piles[l]+dfs(l+1,r,false);
            int case_2=piles[r]+dfs(l,r-1,false);
            dp[l][r]=max(case_1,case_2);
        }
        else{
            int case_1=-piles[l]+dfs(l+1,r,true);
            int case_2=-piles[r]+dfs(l,r-1,true);
            dp[l][r]=min(case_1,case_2);
        }
        return dp[l][r];
    }
    bool stoneGame(vector<int>& piles) {
        this->piles=piles;
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        return dfs(0,n-1,true)>0;
    }
};