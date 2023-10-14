class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& cost, vector<int>& time, int ind, int rem) {
        if (rem <= 0) return 0;
        if (ind == time.size()) return 1e9;
        if (dp[ind][rem] != -1) return dp[ind][rem];
        int t = f(cost, time, ind+1, rem);
        int nt = cost[ind] + f(cost, time, ind+1, rem - time[ind] - 1);
        return dp[ind][rem] = min(t, nt);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        dp.resize(501, vector<int>(501,-1));
        return f(cost, time, 0, time.size());
    }
};