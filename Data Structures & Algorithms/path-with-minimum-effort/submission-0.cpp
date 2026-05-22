class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hts) {
        int row = hts.size();
        int col = hts[0].size();

        vector<vector<int>> effort(row, vector<int>(col, INT_MAX));

        // {effort, row, col}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [e, r, c] = pq.top();
            pq.pop();

            if(r == row-1 && c == col-1) return e;

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < row && nc < col) {
                    int new_effort = max(e, abs(hts[nr][nc] - hts[r][c]));

                    if(new_effort < effort[nr][nc]) {
                        effort[nr][nc] = new_effort;
                        pq.push({new_effort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};