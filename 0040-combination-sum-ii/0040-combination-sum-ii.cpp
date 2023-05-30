class Solution {
public:
    void help(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int k, int sum, int start) {
        if(sum > k) return;
        if(sum == k) {
            res.emplace_back(curr);
            return;
        }
        for(int i=start; i<nums.size(); i++) {
            if(i > start and nums[i] == nums[i-1]) {
                continue;
            }
            curr.emplace_back(nums[i]);
            help(res, curr, nums, k, sum+nums[i], i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        help(res, curr, nums, k, 0, 0);
        return res;
    }
};