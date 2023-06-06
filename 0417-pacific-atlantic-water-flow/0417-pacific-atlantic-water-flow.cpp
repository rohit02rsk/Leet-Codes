class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int m, int n) {
        vis[i][j] = true;
        if (i > 0 && !vis[i - 1][j] && grid[i - 1][j] >= grid[i][j]) {
            dfs(grid, vis, i-1, j, m, n);
        }
        if (i < m - 1 && !vis[i + 1][j] && grid[i + 1][j] >= grid[i][j]) {
            dfs(grid, vis, i+1, j, m, n);
        }
        if (j > 0 && !vis[i][j - 1] && grid[i][j - 1] >= grid[i][j]) {
            dfs(grid, vis, i, j-1, m, n);
        }
        if (j < n - 1 && !vis[i][j + 1] && grid[i][j + 1] >= grid[i][j]) {
            dfs(grid, vis, i, j+1, m, n);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));

        for(int i=0; i<rows; i++) {
            dfs(heights, pacific, i, 0, rows, cols);
            dfs(heights, atlantic, i, cols-1, rows, cols);
        }

        for(int i=0; i<cols; i++) {
            dfs(heights, pacific, 0, i, rows, cols);
            dfs(heights, atlantic, rows-1, i, rows, cols);
        }

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(pacific[i][j] and atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};