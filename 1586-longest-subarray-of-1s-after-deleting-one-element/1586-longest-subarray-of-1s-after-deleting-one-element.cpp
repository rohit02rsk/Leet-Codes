class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        int res = 0;
        int num_zero = 0;
        int i = 0;
        for(int j = 0; j<n; j++) {
            if(nums[j] == 0) num_zero++;
            if(num_zero > 1) {
                while(i < j and nums[i] == 1) i++;
                i++;
                num_zero--;
            }
            res = max(res, j-i);
        }
        return res;
    }
};