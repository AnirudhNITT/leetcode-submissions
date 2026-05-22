class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>& bfs) {
        while (!bfs.empty()) {
            int row = bfs.front().first;
            int col = bfs.front().second;
            bfs.pop();
            if (grid[row][col] == -1) continue;
            if (row > 0 && grid[row-1][col] > grid[row][col] + 1) {
                grid[row-1][col] = grid[row][col] + 1;
                bfs.push({row-1, col});
            }
            if (row + 1 < grid.size() && grid[row+1][col] > grid[row][col] + 1) {
                grid[row+1][col] = grid[row][col] + 1;
                bfs.push({row+1, col});
            }
            if (col > 0 && grid[row][col-1] > grid[row][col] + 1) {
                grid[row][col-1] = grid[row][col] + 1;
                bfs.push({row, col-1});
            }
            if (col + 1 < grid[0].size() && grid[row][col+1] > grid[row][col] + 1) {
                grid[row][col+1] = grid[row][col] + 1;
                bfs.push({row, col+1});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>zeroes;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    zeroes.push({i, j});
                }
            }
        }
        bfs(grid,zeroes);
    }
};
