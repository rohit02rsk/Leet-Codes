class Solution {
public:
    int dfs(int i, int j, int pre, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i<0 or j<0 or i>=m or j>=n or pre >= matrix[i][j])
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = dfs(i, j-1, matrix[i][j], m, n, matrix, dp);
        int r = dfs(i, j+1, matrix[i][j], m, n, matrix, dp);
        int u = dfs(i-1, j, matrix[i][j], m, n, matrix, dp);
        int d = dfs(i+1, j, matrix[i][j], m, n, matrix, dp);

        return dp[i][j] = max(max(l, r), max(u, d)) + 1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                res = max(res, dfs(i, j, -1, m, n, matrix, dp));
            }
        }

        return res;
    }
};