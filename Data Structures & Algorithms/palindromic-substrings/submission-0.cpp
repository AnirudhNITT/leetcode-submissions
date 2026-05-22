class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            count++;
        }
        for(int len=2;len<=n;len++){
            for(int l=0;n>len+l-1;l++){
                int r= l+len-1;
                if(s[l]==s[r]){
                    if(len<=2){
                        dp[l][r]=true;
                        count++;
                    }
                    else{
                        dp[l][r]=dp[l+1][r-1];
                        if(dp[l][r])count++;
                }
                }
            }
        }
        return count;
    }
};
