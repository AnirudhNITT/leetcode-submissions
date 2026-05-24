class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_size=matrix.size();
        int col_size=matrix[0].size();
        vector<vector<bool>>vis(row_size,vector<bool>(col_size,false));
        vector<int>soln;
        vector<vector<int>>curr_dir={{0,1},{1,0},{0,-1},{-1,0}};
        int r=0;
        int c=0;
        int d=0;
        int total_iter=0;
        while(total_iter<row_size*col_size){
            soln.push_back(matrix[r][c]);
            vis[r][c]=true;
            int nr=r+curr_dir[d][0];
            int nc=c+curr_dir[d][1];
            if(nr<0 || nc<0 ||nr>=row_size ||nc>=col_size ||vis[nr][nc]){
                d=(d+1)%4;
                r=r+curr_dir[d][0];
                c=c+curr_dir[d][1];
            }
            else{
                r=nr;
                c=nc;
            }
            total_iter++;
        }
        return soln;
    }
};
