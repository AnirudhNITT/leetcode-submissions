class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool>trusts_someone(n+1,false);
        vector<int>is_trusted(n+1,0);
        for(auto it :trust){
            trusts_someone[it[0]]=true;
            is_trusted[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(!(trusts_someone[i])&&(is_trusted[i]==n-1))return i;
        }
        return -1;
    }
};