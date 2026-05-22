class Solution {
public:
    int INF =1e9;
    int coinChange(vector<int>& coins, int amount) {
        int size=amount+1;
        vector<int>dp(size,INF);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto &coin : coins){
                if(i-coin<0)continue;
                dp[i]=min(dp[i], dp[i-coin]+1);
            }
        }
        return (dp[amount]<INF)?dp[amount]:-1;
    }
};
