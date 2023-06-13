class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int pref = 0;
        int res = INT_MIN;
        while(i < n) {
            pref += nums[i];
            res = max(res, pref);
            if(pref < 0) {
                pref = 0;
            }
            i++;
        }
        return res;
    }
};