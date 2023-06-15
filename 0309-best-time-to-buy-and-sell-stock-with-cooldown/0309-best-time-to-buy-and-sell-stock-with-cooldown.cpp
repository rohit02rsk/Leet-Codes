class Solution {
public:
    map<pair<int, bool>, int> dp;
    int dfs(vector<int>& prices, int ind, bool buying) {
        if(ind >= prices.size() or ind < 0)
            return 0;
        if(dp.find({ind, buying}) != dp.end())
            return dp[{ind, buying}];
        int cool = dfs(prices, ind+1, buying);
        if(buying) {
            int buy = dfs(prices, ind+1, false) - prices[ind];
            return max(cool, buy);
        }
        int sell = dfs(prices, ind+2, true) + prices[ind];
        dp[{ind, buying}] = max(cool, sell);
        return max(cool, sell);
    }
    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, true);
    }
};