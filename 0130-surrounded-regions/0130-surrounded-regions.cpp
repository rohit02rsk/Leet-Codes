class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if(i<0 or j<0 or i>=m or j>=n or grid[i][j] != 'O')
            return;
        grid[i][j] = 'T';
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int it=0; it<4; it++) {
            auto [di, dj] = dir[it];
            dfs(grid, i+di, j+dj, m, n);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m < 3 or n < 3) return;
        
        for(int i=0; i<m; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0, m, n);
            if(board[i][n-1] == 'O')
                dfs(board, i, n-1, m, n);
        }

        for(int i=0; i<n; i++) {
            if(board[0][i] == 'O')
                dfs(board, 0, i, m, n);
            if(board[m-1][i] == 'O')
                dfs(board, m-1, i, m, n);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};