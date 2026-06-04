class Solution {
public:
    int dfs(vector<vector<int>>&dp,vector<vector<int>>&grid,int row,int col){
        if(row+1>dp.size() || col+1>dp[0].size())return 0;
        if(grid[row][col]==1)return 0;
        if(row==dp.size()-1 && col==dp[0].size()-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        dp[row][col]=dfs(dp,grid,row+1,col)+dfs(dp,grid,row,col+1);
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row= grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return dfs(dp,grid,0,0);
        
    }
};