class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int r=1;
        int ans=0;
        while(r<prices.size()){
            int l=0;
            while(l<r){
                if (prices[r]-prices[l]>ans)ans=prices[r]-prices[l];
                l++;
            }
            r++ ;

        }
        return ans;
    }
};
