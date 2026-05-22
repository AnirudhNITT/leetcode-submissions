class Solution {
public:
    vector<string>soln;
    string path;
    void backtrack(string &input,int i,unordered_map<char,string> &mp){
        
        
        if(path.size()==input.size()){
            soln.push_back(path);
            return;
        }
        string &letters = mp[input[i]];
        for(int j=0;j<letters.size();j++){
            path.push_back(letters[j]);
            backtrack(input,i+1,mp);
            path.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    if (digits.size()==0)return soln;
    backtrack(digits,0,mp);
    return soln;

    }
};
