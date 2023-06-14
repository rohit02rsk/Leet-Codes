class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while(i < n) {
            if(i > 0 and intervals[i][0] <= intervals[i-1][1]) {
                // merge
                vector<int> temp(2);
                temp[0] = min(intervals[i][0], intervals[i-1][0]);
                temp[1] = max(intervals[i-1][1], intervals[i][1]);
                while(i < n and temp[1] >= intervals[i][0]) {
                    temp[1] = max(temp[1], intervals[i][1]);
                    i++;
                }
                res.emplace_back(temp);
            }
            else if(i < n-1 and intervals[i][1] >= intervals[i+1][0]) {
                i++;
            }
            else {
                res.emplace_back(intervals[i]);
                i++;
            }
        }
        return res;
    }
};