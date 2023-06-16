class Solution {
public:
    int dfs(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            dp[i][j] = dfs(s, t, i+1, j+1, dp) + dfs(s, t, i+1, j, dp);
        else
            dp[i][j] = dfs(s, t, i+1, j, dp);
        
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = s.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(s, t, 0, 0, dp);
    }
};