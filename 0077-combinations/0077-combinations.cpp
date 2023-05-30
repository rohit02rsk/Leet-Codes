class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& curr, int n, int start, int k) {
        if(curr.size() == k) {
            res.emplace_back(curr);
            return;
        }
        // curr.emplace_back(start);
        for(int i=start; i<=n; i++) {
            curr.emplace_back(i);
            help(res, curr, n, i+1, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        help(res, curr, n, 1, k);
        return res;
    }
};