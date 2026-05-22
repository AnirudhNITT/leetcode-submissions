class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s_1=s1.size();
        int s_2=s2.size();
        int s_3=s3.size();
        if(s_1+s_2!=s_3)return false;
        vector<vector<bool>>dp(s_1+1,vector<bool>(s_2+1));
        dp[s_1][s_2]=true;
        for(int i=s_1;i>=0;i--){
            for(int j=s_2;j>=0;j--){
                if(i<s_1 && s1[i]==s3[i+j] &&dp[i+1][j])dp[i][j]=true;
                if(j<s_2 && s2[j]==s3[i+j] &&dp[i][j+1])dp[i][j]=true;
            }
        }
        return dp[0][0];
    }
};
