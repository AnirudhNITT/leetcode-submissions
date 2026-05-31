class Solution {
public:
    bool is_feasible(vector<int>&wts,int days,int curr_wt){
        int day=1;
        int wt=curr_wt;          
        for(auto it : wts){
            
            if(wt-it<0){
                day++;
                wt=curr_wt;
                if(day>days)return false;
                wt-=it;
            }
            else{
                wt-=it;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum_wt=0;
        int max_wt=0;
        for(auto wt :weights){
            max_wt=max(max_wt,wt);
            sum_wt+=wt;
        }
        int l=max_wt;
        int r=sum_wt;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(is_feasible(weights,days,mid))r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};