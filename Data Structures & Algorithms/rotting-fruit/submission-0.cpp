class Solution {
public:
    int bfs(vector<vector<int>>& grid,
            queue<pair<int,int>>& rotten,
            int fresh) {

        int minutes = 0;
        int row_dir[4] = {-1, 1, 0, 0};
        int col_dir[4] = {0, 0, -1, 1};

        while (!rotten.empty() && fresh > 0) {
            int size = rotten.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = rotten.front();
                rotten.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = row + row_dir[k];
                    int nc = col + col_dir[k];

                    if (nr < 0 || nr >= grid.size() ||
                        nc < 0 || nc >= grid[0].size() ||
                        grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    rotten.push({nr, nc});
                    fresh--;
                }
            }
            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) rotten.push({i, j});
            }
        }

        return bfs(grid, rotten, fresh);
    }
};

