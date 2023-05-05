class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0, r=0;
        int sum = 0;
        int res = INT_MAX;
        
        while(r < nums.size()) {
            sum += nums[r];
            if(sum < target) {
                r++;
            } else {
                while(sum >= target) {
                    res = min(res, r-l+1);
                    sum -= nums[l];
                    l++;
                }
                r++;
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};