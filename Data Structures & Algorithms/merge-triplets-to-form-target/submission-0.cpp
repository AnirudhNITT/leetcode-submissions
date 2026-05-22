class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a1=target[0];
        int a2=target[1];
        int a3=target[2];
        int c1=0;
        int c2=0;
        int c3=0;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]==a1 &&triplets[i][1]<=a2 && triplets[i][2]<=a3)c1++;
            if(triplets[i][0]<=a1 &&triplets[i][1]==a2 && triplets[i][2]<=a3)c2++;
            if(triplets[i][0]<=a1 &&triplets[i][1]<=a2 && triplets[i][2]==a3)c3++;
        }
        if(c1>0 && c2>0 && c3>0)return true;
        else return false;
        
    }
};
