class Solution {
public:
    vector<string>soln;
    string path;
    void backtrack(int open,int close,int n){
        if(path.size()==2*n){
            soln.push_back(path);
            return;
        }
    
        if(open<n){
            path.push_back('(');
            backtrack(open+1,close,n);
            path.pop_back();
        }
        if(close<open){
            path.push_back(')');
            backtrack(open,close+1,n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       backtrack(0,0,n);
       return soln;
    }
};