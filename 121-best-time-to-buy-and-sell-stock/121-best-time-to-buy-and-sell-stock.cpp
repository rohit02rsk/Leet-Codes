class Solution {
public:
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX;
        int md = 0;
        for(int i= 0 ; i<n ; i++) {
            if(prices[i] < min) min = prices[i];
            md = max(md, prices[i] - min);
        }      
        return md;
    }
};