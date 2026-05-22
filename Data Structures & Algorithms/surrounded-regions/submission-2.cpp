class Solution {
public:
    void dfs(vector<vector<char>>& board,int row,int col){
        if(board[row][col]=='X'||board[row][col]=='#')return;
        if(board[row][col]=='O'){
            board[row][col]='#';
        }
        
        if(row+1<board.size())dfs(board,row+1,col);
        if(col+1<board[0].size())dfs(board,row,col+1);
        if(row-1>=0)dfs(board,row-1,col);
        if(col-1>=0)dfs(board,row,col-1);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1)dfs(board,i,j);
            }
        }
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='#')board[i][j]='O';
            }
        }

    }
};
