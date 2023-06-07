class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = -1;
        int fresh = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        
        if(m == 1 and n == 1) {
            if(grid[0][0] == 1) return -1;
            return 0;
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        if(!fresh) return 0;

        while(!q.empty()) {
            int sz = q.size();
            for(int it=0; it<sz; it++) {
                auto [i, j] = q.front();
                q.pop();
                for(int k=0; k<4; k++) {
                    auto [di, dj] = dir[k];
                    int x = i + di;
                    int y = j + dj;
                    if(x>=0 and x<m and y>=0 and y<n and grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
            res++;
        }
        return !fresh ? res : -1;
    }
};