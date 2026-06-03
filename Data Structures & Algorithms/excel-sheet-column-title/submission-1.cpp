class Solution {
public:
    string convertToTitle(int col) {
        string soln="";
        while(col>0){
            col--;
            soln.push_back('A'+(col%26));
            col/=26;
        }
        reverse(soln.begin(),soln.end());
        return soln;
    }
};