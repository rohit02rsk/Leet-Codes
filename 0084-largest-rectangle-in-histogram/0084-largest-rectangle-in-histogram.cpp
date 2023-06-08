class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int res = 0;
        int n = heights.size();
        for(int i=0; i<n; i++) {
            int start = i;
            while(!st.empty() and st.top().first > heights[i]) {
                auto [h, ind] = st.top();
                res = max(res, h*(i - ind));
                start = ind;
                st.pop();
            }
            st.push({heights[i], start});
        }
        while(!st.empty()) {
            auto [h, ind] = st.top();
            res = max(res, h*(n - ind));
            st.pop();
        }
        return res;
    }
};