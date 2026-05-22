class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0;
        int left=0;
        vector<int>freq(26,0);
        int maxfreq=0;
        int ans=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            if(freq[s[right]-'A']>maxfreq)maxfreq=freq[s[right]-'A'];
            while((right-left+1)-maxfreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            ans= (ans>(right-left+1))?ans:(right-left+1) ;
        }
      return ans;  
    }
};
