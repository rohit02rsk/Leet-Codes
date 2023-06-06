class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        if(i<0 or i>=rows or j<0 or j>=cols or grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        
        vector<pair<int, int>> arr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int it=0; it<4; it++) {
            auto [dr, dc] = arr[it];
            dfs(grid, i+dr, j+dc, rows, cols);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, rows, cols);
                    res++;
                }
            }
        }
        return res;
    }
};