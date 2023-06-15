class Solution {
public:
    map<pair<int, int>, int> dp;
    int help(vector<int>& nums, int target, int i, int curr) {
        if(i == nums.size()) {
            return target == curr ? 1 : 0;
        }
        if(dp.find({i, curr}) != dp.end())
            return dp[{i, curr}];
        return dp[{i, curr}] = 
            help(nums, target, i+1, curr + nums[i]) +
            help(nums, target, i+1, curr - nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return help(nums, target, 0, 0);
    }
};