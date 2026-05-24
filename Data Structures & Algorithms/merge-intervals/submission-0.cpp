class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),comp);
        vector<vector<int>> ans;
        int i=0;
        int size=inter.size();
        while(i<size){
            int start=inter[i][0];
            int end=inter[i][1];
            i++;
            while(i<size && inter[i][0]<=end){
                end=max(end,inter[i][1]);
                i++;
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};