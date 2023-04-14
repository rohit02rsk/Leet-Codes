class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i=n-1; i >= 0; i--) {
            vector<int> temp(n, 0);
            temp[i] = 1;
            for (int j=i+1; j < n; j++) {
                if(s[i] == s[j]) {
                    temp[j] = 2 + dp[j-1];
                } else {
                    temp[j] = max(dp[j], temp[j-1]);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};