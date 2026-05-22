class Solution {
public:
    
    bool isSafe(int row,int col,vector<string>& soln,int n){
        for(int i=0;i<row;i++){
            if(soln[i][col]=='Q')return false;

        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(soln[i][j]=='Q')return false;

        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(soln[i][j]=='Q')return false;

        }
        return true;
    }

    void backtrack(vector<string>&input,int row,int size,vector<vector<string>>&ans){
        if(row==size){
            ans.push_back(input);
            return;
        }
        for(int col=0;col<size;col++){
            if(isSafe(row,col,input,size)){
                input[row][col]='Q';
                backtrack(input,row+1,size,ans);
                input[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>input(n,string(n,'.'));
        vector<vector<string>>ans;
        backtrack(input,0,n,ans);
        return ans;
    }
};