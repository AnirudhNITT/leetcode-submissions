class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>change(3,0);
        if(bills[0]>5)return false;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)change[0]++;
            if(bills[i]==10){
                change[1]++;
                if(change[0]<1)return false;
                change[0]--;
            }
            if(bills[i]==20){
                change[2]++;
                if(change[0]<1)return false;
                if(change[1]<1){
                    if(change[0]<3)return false;
                    else change[0]-=3;
                }
                change[0]--;
                change[1]--;
            }
        }
        return true;
    }
};