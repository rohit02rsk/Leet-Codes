class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top_sum = grid[0][0], bot_sum = 0, res = LONG_MAX;
        for(int i = 1; i<grid[0].size(); i++)
            top_sum += grid[0][i];
        
        for(int i =0; i<grid[0].size(); i++) {
            top_sum -= grid[0][i];
            res = min(res, max(top_sum, bot_sum));
            bot_sum += grid[1][i];
        }

        return res;
    }
};