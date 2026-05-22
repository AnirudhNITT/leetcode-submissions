class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<
        pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<vector<int>> dir = 
        {{-1,0},{1,0},{0,-1},{0,1}};
        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == n-1)
                return wt;
            for(auto &d : dir) {
                int nr = row + d[0];
                int nc = col + d[1];
                if(nr>=0 && nc >= 0 && nr < n && nc < n){
                    int temp = max(wt, grid[nr][nc]);
                    if(temp < dist[nr][nc]) {
                        dist[nr][nc] = temp;
                        pq.push({temp, {nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};