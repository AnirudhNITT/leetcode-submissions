class Solution {
public:
    static bool comp(vector<int>a ,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),comp);
        stack<vector<int>,vector<vector<int>>>st;
        for(int i=0;i<intervals.size();i++){
            if(st.empty()){
                st.push(intervals[i]);
                continue;
            }
            int count=0;
            int start;
            auto curr=intervals[i];
            int end;
            while(!st.empty() && st.top()[1]>=curr[0]){
                start=st.top()[0];
                end=max(st.top()[1],curr[1]);
                st.pop();
                count++;
            }
            if(count>0)st.push({start,end});
            else st.push(curr);

        }
        vector<vector<int>>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
