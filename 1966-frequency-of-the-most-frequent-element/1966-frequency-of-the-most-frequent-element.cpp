class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        long long int curr = 0;
        int res = 0;
        for(int j=0; j<nums.size(); j++) {
            curr += nums[j];
            if(curr + k < 1LL*(j-i+1)*nums[j]) {
                curr -= nums[i];
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};