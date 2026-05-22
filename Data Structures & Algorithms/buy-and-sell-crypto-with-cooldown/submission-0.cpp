class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>hold(n,0);
        vector<int>reset(n,0);
        vector<int>sold(n,0);
        hold[0]=-prices[0];
        reset[0]=0;
        sold[0]=0;
        for(int i=1;i<n;i++){
            hold[i]=max(hold[i-1],reset[i-1]-prices[i]);
            reset[i]=max(reset[i-1],sold[i-1]);
            sold[i]=hold[i-1]+prices[i];
        }
        return max(sold[n-1],reset[n-1]);
    }
};
