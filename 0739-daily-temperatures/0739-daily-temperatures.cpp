class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int, int>> stk;
        int n = arr.size();
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            int day = i;
            int temp = arr[i];
            while(!stk.empty() and stk.top().second < temp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                res[prevDay] = day - prevDay;
            }
            stk.push({day, temp});
        }
        return res;
    }
};