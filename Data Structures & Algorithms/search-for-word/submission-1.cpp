class Solution {
public:
    bool backtrack(vector<vector<char>>& board,string word,int index,int row,int col){
        if(index==word.size())return true;
        if(row>=board.size()|| row<0 ||col<0 || col>=board[0].size() || board[row][col]!=word[index])return false;
        else{
            char temp=board[row][col];
            board[row][col]='#';
           bool found=( backtrack(board,word,index+1,row+1,col)||
            backtrack(board,word,index+1,row,col+1) ||
            backtrack(board,word,index+1,row-1,col)||
            backtrack(board,word,index+1,row,col-1));
            board[row][col]=temp;
            return found;
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtrack(board,word,0,i,j))return true;
            }
        }
        return false;
    }
};
