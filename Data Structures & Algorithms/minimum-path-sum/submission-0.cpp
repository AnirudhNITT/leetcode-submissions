class Solution {
public:
    int dfs(vector<vector<int>>&grid,vector<vector<int>>& dp,int row,int col){
        if(row>=grid.size() || col>=grid[0].size())return 50000;
        if(row==grid.size()-1 && col==grid[0].size()-1)return grid[row][col];
        if(dp[row][col]!=-1)return dp[row][col];
        dp[row][col]=min(dfs(grid,dp,row+1,col),dfs(grid,dp,row,col+1))+grid[row][col];
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return dfs(grid,dp,0,0);
    }
};