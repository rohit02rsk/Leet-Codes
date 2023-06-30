class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool bfs(int m, int n, int t, vector<vector<int>>& cells) {
        vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < t; i++)
            grid[cells[i][0]][cells[i][1]] = 1;

        for (int i = 1; i <= n; i++) {
            if (grid[1][i] == 0) {
                q.push({1, i});
                grid[1][i] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc; 
                if (nr > 0 and nc > 0 and nr <= m and nc <= n and grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; 
                    if (nr == m)
                        return true;
                    q.push({nr, nc}); 
                }
            }
        }

        return false; 
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0;
        int r = row*col;
        int latestPossibleDay = 0;
        while (l < r-1) {
            int mid = l + (r - l) / 2; 
            if (bfs(row, col, mid, cells)) {
                latestPossibleDay = mid; 
                l = mid; 
            } 
            else r = mid;
        }
        return latestPossibleDay;
    }
};