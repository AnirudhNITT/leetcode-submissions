class Solution {
public:
    bool backtrack(vector<int>&sides,vector<int>& matchsticks,int curr_indx,int target_sum){
        if(curr_indx==matchsticks.size()){
            return(sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]);
        }
        for(int i=0;i<4;i++){
            if(sides[i]+matchsticks[curr_indx]>target_sum)continue;
            sides[i]+=matchsticks[curr_indx];          
            if(backtrack(sides,matchsticks,curr_indx+1,target_sum))return true;
            sides[i]-=matchsticks[curr_indx];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        int target_sum=0;
        for (auto it : matchsticks){
            target_sum+=it;
        }
        if((target_sum)%4!=0)return false;
        vector<int>sides(4,0);
        return backtrack(sides,matchsticks,0,target_sum/4);
    }
};