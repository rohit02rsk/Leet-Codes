class Solution {
public:
    set<vector<int>> s;
    void help(vector<vector<int>>& res, vector<int>& nums, int start, int n) {
        if(start == n and !s.count(nums)) {
            res.emplace_back(nums);
            s.insert(nums);
            return;
        }
        for(int i=start; i<n; i++) {
            if(i > start and nums[i] == nums[i-1]) continue;
            swap(nums[start], nums[i]);
            help(res, nums, start+1, n);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        help(res, nums, 0, nums.size());
        return res;
    }
};