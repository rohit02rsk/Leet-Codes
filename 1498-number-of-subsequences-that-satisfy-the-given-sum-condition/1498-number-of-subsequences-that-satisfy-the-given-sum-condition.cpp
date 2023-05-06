class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        int mod = 1e9+7;
        sort(nums.begin(), nums.end());
        
        vector<int> pow2(n+1, 1);
        for(int i=1; i<=n; i++) {
            pow2[i] = (2*pow2[i-1]) % mod;
        }
        
        int i=0, j=n-1;
        while(i <= j) {
            if(nums[j] + nums[i] <= target) {
                res = (res+pow2[j-i]) % mod;
                i++;
            }
            else j--;
        }

        return res;
    }
};