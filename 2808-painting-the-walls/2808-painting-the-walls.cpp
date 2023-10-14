class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& cost, vector<int>& time, int ind, int rem) {
        if (rem <= 0) return 0;
        if (ind == time.size()) return 1e9;
        if (dp[ind][rem] != 0) return dp[ind][rem];
        return dp[ind][rem] = min(
            f(cost, time, ind+1, rem),
            cost[ind] + f(cost, time, ind+1, rem - time[ind] - 1)
        );
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        dp.resize(501, vector<int>(501,0));
        return f(cost, time, 0, time.size());
    }
};