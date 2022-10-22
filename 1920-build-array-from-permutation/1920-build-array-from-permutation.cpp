class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i: nums) {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};