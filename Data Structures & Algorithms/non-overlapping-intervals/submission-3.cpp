class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        if(a[1]<b[1])return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=0;
        int prev=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=intervals[prev][1]){
                count++;
                prev=i;
            }
        }
        return (intervals.size()-count-1);
    }
};
