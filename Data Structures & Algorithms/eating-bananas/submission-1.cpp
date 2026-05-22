class Solution {
public:
int time_req(vector<int>& piles, int k){
        int hours=0;
        for(int p : piles){
            hours+=ceil((double)p/k);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_rate=piles[0];
        for(int p :piles){
            if(max_rate<p){
                max_rate=p;
            }
        }
        int min_rate=1;
        int ans;
        while(min_rate<=max_rate){
            int mid_rate=min_rate+(max_rate-min_rate)/2;
            int time=time_req(piles,  mid_rate);
            if(time<=h){
                max_rate=mid_rate-1;
                ans=mid_rate;
            }
            else{
                min_rate=mid_rate+1;
            }
        }
        return ans;
    }
};
