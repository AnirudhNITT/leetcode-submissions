class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>soln;
        unordered_map<string,vector<string>>hash;
        for(int i=0;i<strs.size();i++){
            vector<int>temp(26,0);
            for (int j=0;j<strs[i].size();j++){
                temp[strs[i][j]-'a']++ ;
            }
            string s;
            for(int k=0;k<26;k++){
                s+=to_string(temp[k])+'#';
            }
            hash[s].push_back(strs[i]);
        }
        for(auto &x : hash){
            soln.push_back(x.second);
        }
        return soln;
    }
};
