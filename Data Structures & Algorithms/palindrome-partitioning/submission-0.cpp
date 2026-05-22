class Solution {
public:
    bool isPalindrome(string s){
        if(s.size()==0)return false;
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>>soln;
    vector<string>path;
    void backtrack(string s,int i){
        if(i==s.size()){
            soln.push_back(path);
            return;
        }
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,(j-i+1));
            if(isPalindrome(temp)){
                path.push_back(temp);
                backtrack(s,j+1);
                path.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return soln;
    }
};
