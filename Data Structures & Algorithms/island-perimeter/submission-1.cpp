class Solution {
public:
    int dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int row,int col,int ans){
        vis[row][col]=true;
        int r_l=0;
        int l_l=0;
        int u_l=0;
        int d_l=0;
        if(row-1>=0 && grid[row-1][col]==1){
            u_l=1;
            if(!vis[row-1][col])ans+=dfs(grid,vis,row-1,col,0);
        }
        if(row+1<grid.size() && grid[row+1][col]==1){
            d_l=1;
            if(!vis[row+1][col])ans+=dfs(grid,vis,row+1,col,0);
        }
        if(col-1>=0 && grid[row][col-1]==1){
            l_l=1;
            if(!vis[row][col-1])ans+=dfs(grid,vis,row,col-1,0);
        }
        if(col+1<grid[0].size() && grid[row][col+1]==1){
            r_l=1;
            if(!vis[row][col+1])ans+=dfs(grid,vis,row,col+1,0);
        }
        ans=ans+4-(l_l+r_l+u_l+d_l);
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int soln=0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j])soln+=dfs(grid,vis,i,j,0);
            }
        }
        return soln;
    }
};