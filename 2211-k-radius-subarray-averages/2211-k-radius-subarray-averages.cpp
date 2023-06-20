class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int len = 2*k + 1;
        int n = nums.size();
        vector<int> res(n, -1);
        int l = 0;
        int r = 0;
        long long int avg = 0;
        while(r < nums.size()) {
            avg += nums[r];
            if(r-l+1 == len) {
                res[(r+l)/2] = avg / (r-l+1);
                avg -= nums[l];
                l++;
            }
            r++;
        }
        return res;
    }
};