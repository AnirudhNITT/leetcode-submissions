class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int start=0;
        int far=mp[s[0]];
            for(int i=0;i<s.size();i++){
                far=max(far,mp[s[i]]);
                if(i==far){
                    ans.push_back(far-start+1);
                    start=i+1;
                }
            }
        return ans;
    }
};
