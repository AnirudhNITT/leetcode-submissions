class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_prices=prices[0];
        int max_profit=0;
        for(int p :prices){
            if(min_prices>p){
                min_prices=p;
                }
            if(p-min_prices>max_profit){
                max_profit=p-min_prices;
            }
        }
        return max_profit;
    }
};
