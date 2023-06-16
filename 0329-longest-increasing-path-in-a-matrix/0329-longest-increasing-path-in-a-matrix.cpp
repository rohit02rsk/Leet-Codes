class Solution {
public:
    map<pair<int, int>, int> dp; // {i, j} -> max len
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        if(i < 0 or j < 0 or i >= m or j >= n)
            return 1;
        
        if(dp.find({i, j}) != dp.end()) 
            return dp[{i, j}];
        
        int LIP = 0;
        
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int it=0; it<4; it++) {
            int x = i + dir[it][0];
            int y = j + dir[it][1];
            if(x>=0 and y>=0 and x<m and y<n and matrix[x][y] > matrix[i][j]) {
                LIP = max(LIP, 1 + dfs(matrix, x, y, m, n));
            }
        }

        dp[{i, j}] = LIP;
        return LIP;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                res = max(res, 1 + dfs(matrix, i, j, m, n));

        return res;
    }
};