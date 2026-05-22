class Solution{
public:
    string minWindow(string s,string t){
        vector<int>freq(128,0);
        for(char c:t)freq[c]++;
        int l=0,r=0,curr_count=t.size();
        int minLen=INT_MAX,start=0;
        while(r<s.size()){
            if(freq[s[r]]>0)curr_count--;
            freq[s[r]]--;
            while(curr_count==0){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0)curr_count++;
                l++;
            }
            r++;
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};