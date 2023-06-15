class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1));
        
        for(int i=0; i<n; i++)
            dp[i][0] = 1;
        
        for(int j=1; j<=amount; j++) {
            for(int i=n-1; i>=0; i--) {
                int left = 0, bot = 0;
                if(i < n-1)
                    left = dp[i+1][j];
                if(j-coins[i] >= 0)
                    bot = dp[i][j - coins[i]];
                dp[i][j] = left + bot;
            }
        }

        return dp[0][amount];
    }
};