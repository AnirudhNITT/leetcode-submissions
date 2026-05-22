class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s1=0,s2=0;
        for(int i=0;i<gas.size();i++){
            s1+=gas[i];
            s2+=cost[i];
        }
        if(s2>s1)return -1;
        int total=0;
        int result=0;
        for(int i=0;i<gas.size();i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
                result=i+1;
                total=0;
        }
        }
        return result;
    }
};
