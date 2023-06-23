class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        stack<pair<int, int>> stk;
        for(int i=0; i<n; i++) {
            int start = i;
            while(!stk.empty() and stk.top().first > heights[i]) {
                auto [h, ind] = stk.top();
                res = max(res, h*(i - ind));
                start = ind;
                stk.pop();
            }
            stk.push({heights[i], start});
        }
        while(!stk.empty()) {
            auto [h, ind] = stk.top();
            res = max(res, h*(n - ind));
            stk.pop();
        }
        return res;
    }
};