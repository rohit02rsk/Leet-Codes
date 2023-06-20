class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i < n; i++) {
            if(nums[i] > 0)
                return res;
            if(i > 0 and nums[i] == nums[i-1])
                continue;
            int l = i+1;
            int r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int ll = nums[l];
                    int lh = nums[r];
                    while(l < r and nums[l] == ll) l++;
                    while(l < r and nums[r] == lh) r--;
                }
            }
        }
        return res;
    }
};