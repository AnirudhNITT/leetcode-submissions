class Solution {
public:
    void dfs(vector<vector<int>>&heights,vector<vector<bool>>&psbl,stack<pair<int,int>> &st){
        while(!st.empty()){
            auto[r,c]=st.top();
            st.pop();
            if (psbl[r][c]==true) continue;
            psbl[r][c]=true;

            if(r-1>=0 && heights[r-1][c]>=heights[r][c] &&psbl[r-1][c]==false){
                st.push({r-1,c});
            
            }
            if(r+1<heights.size()&& heights[r+1][c]>=heights[r][c] && psbl[r+1][c]==false){
                st.push({r+1,c});
             
            }
            if(c-1>=0 && heights[r][c-1]>=heights[r][c] && psbl[r][c-1]==false){
                st.push({r,c-1});
              
            }
            if(c+1< heights[0].size()&& heights[r][c+1]>=heights[r][c] && psbl[r][c+1]==false){
                st.push({r,c+1});
               
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        stack<pair<int,int>>pacific;
        stack<pair<int,int>>atlantic;
        vector<vector<bool>>psbl1(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>>psbl2(heights.size(),vector<bool>(heights[0].size(),false));
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(i==0 || j==0)pacific.push({i,j});
                if(i==heights.size()-1 || j==heights[0].size()-1)atlantic.push({i,j});
            }
        }
        dfs(heights,psbl1,pacific);
        dfs(heights,psbl2,atlantic);
        vector<vector<int>>soln;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(psbl1[i][j] && psbl2[i][j])soln.push_back({i,j});
            }
         }

        return soln;
    }
};
