class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 or k + maxPts <= n) return 1.0;
        vector<double> dp(n+1);
        double currSum = 1.0;
        double res = 0.0;
        dp[0] = 1.0;
        
        for(int i=1; i<=n; i++) {
            dp[i] = currSum / maxPts;
            if(i < k) {
                currSum += dp[i];
            }
            else {
                res += dp[i];
            }
            if(i >= maxPts) {
                currSum -= dp[i-maxPts];
            }
        }
        
        return res;
    }
};