class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cd = 0, sell = 0, hold = INT_MIN;
        for(int i: prices) {
            int prevCD = cd, prevSell = sell, prevHold = hold;
            cd = max(prevCD, prevSell);
            sell = prevHold + i;
            hold = max(prevHold, prevCD - i);
        }
        return max(sell, cd);
    }
};