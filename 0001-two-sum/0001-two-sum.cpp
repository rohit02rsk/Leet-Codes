class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0; i<n; i++) m[nums[i]] = i;
        for(int i=0; i<n; i++) {
            int rem = target-nums[i];
            if(m.find(rem) != m.end() && m[rem] != i) {
                return {i, m[rem]};
            }
        }
        return {};
    }
};