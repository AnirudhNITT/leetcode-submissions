class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(dp[row][col]!=0)return dp[row][col];
        int soln=1;
        if(row-1>=0 && mat[row-1][col]>mat[row][col]){
            soln=max(soln,1+dfs(row-1,col,mat,dp));
        }
        if(row+1<mat.size() && mat[row+1][col]>mat[row][col]){
            soln=max(soln,1+dfs(row+1,col,mat,dp));
        }
        if(col-1>=0 && mat[row][col-1]>mat[row][col]){
            soln=max(soln,1+dfs(row,col-1,mat,dp));
        }
        if(col+1<mat[0].size() && mat[row][col+1]>mat[row][col]){
            soln=max(soln,1+dfs(row,col+1,mat,dp));
        }
        dp[row][col]=soln;
        return soln;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
