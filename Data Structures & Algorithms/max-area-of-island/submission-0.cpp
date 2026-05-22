class Solution {
public:
    int dfs_count(vector<vector<int>>&grid,int row,int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0)return 0;
        grid[row][col]=0;
        return 1+dfs_count(grid,row+1,col)+dfs_count(grid,row,col+1)+dfs_count(grid,row-1,col)+dfs_count(grid,row,col-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_num=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    max_num=max(max_num,dfs_count(grid,i,j));
            }
            }
        }
        return max_num;
    }
};
