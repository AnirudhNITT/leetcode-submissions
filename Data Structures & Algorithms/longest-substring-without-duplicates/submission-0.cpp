class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>hash;
        int l=0;
        int r=0;
        int size=0;
        
        while(r<s.size()){
            if(hash.count(s[r])==0){
                hash.insert(s[r]);
                size=(size>(r-l+1))?size:(r-l+1);
                r++;
            }
            else{
                while(s[l]!=s[r]){
                    hash.erase(s[l]);
                    l++;
                }
                hash.erase(s[l++]);
            }
        }
        return size;
    }
};
