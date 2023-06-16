class Solution {
public:
    bool dfs(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if(j >= p.size() and i >= s.size())
            return 1;

        if(j >= p.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        bool match = i < s.size() and (s[i] == p[j] or p[j] == '.');

        if(j < p.size() - 1 and p[j+1] == '*') {
            return dp[i][j] = dfs(s, p, i, j+2, dp) or (match and dfs(s, p, i+1, j, dp));
        }

        if(match) {
            return dp[i][j] = dfs(s, p, i+1, j+1, dp);
        }

        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return dfs(s, p, 0, 0, dp);
    }
};