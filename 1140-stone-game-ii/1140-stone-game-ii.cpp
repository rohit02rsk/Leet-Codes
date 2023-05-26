class Solution {
public:
    int dp[101][201];
    int help(int i,int m, vector<int>& piles) {
        if(i >= piles.size())
            return 0;
        if(dp[i][m] != -1)
            return dp[i][m];
        
        int total = 0;
        int res = INT_MIN;
        for(int j = 0; j < 2*m; j++){
            if(i+j < piles.size())
                total += piles[i+j];

            res = max(res, total-help(i+j+1, max(m, j+1), piles));
        }
        
        return dp[i][m] = res;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof dp);
        
        int sum = 0;
        for(auto x : piles)
            sum += x;
        
        int diff = help(0, 1, piles);
        return (sum + diff) / 2;
    }
};