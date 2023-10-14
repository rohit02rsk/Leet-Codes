// class Solution {
// public:
//     vector<vector<int>> dp;
//     int f(vector<int>& cost, vector<int>& time, int ind, int rem) {
//         if (rem <= 0) return 0;
//         if (ind == time.size()) return 1e9;
//         if (dp[ind][rem] != 0) return dp[ind][rem];
//         return dp[ind][rem] = min(
//             f(cost, time, ind+1, rem),
//             cost[ind] + f(cost, time, ind+1, rem - time[ind] - 1)
//         );
//     }
//     int paintWalls(vector<int>& cost, vector<int>& time) {
//         dp.resize(501, vector<int>(501,0));
//         return f(cost, time, 0, time.size());
//     }
// };
int dp[501][501];
class Solution {
    int n;
public:
    int helper(vector<int>&cost, vector<int>&time, int idx, int unpainted){
        if(unpainted <= 0) return 0;
        if(idx == n) return 1e9; 
        if(dp[idx][unpainted] != -1) return dp[idx][unpainted];

        int choose, skip;
        choose = cost[idx] + helper(cost, time, idx+1, unpainted-1-time[idx]);
        skip = helper(cost, time, idx+1, unpainted);
        
        return dp[idx][unpainted] = min(choose, skip);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(dp, -1, sizeof dp);

        return helper(cost, time, 0, n);
    }
};