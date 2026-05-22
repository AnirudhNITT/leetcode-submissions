class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<=n;i++){
            int curr_ht=(i==n)?0:heights[i];
            while(!st.empty() && curr_ht<heights[st.top()]){
                int right=st.top();
                st.pop();
                int w=(st.empty())?i:(i-st.top()-1);
                max_area=max(max_area,heights[right]*w);
            }
            st.push(i);
        }
        return max_area;
    }
};