class Solution {
public:
    long long calcCost(vector<int>& nums, vector<int>& cost, int m) {
        long long res = 0;
        for(int i=0; i<nums.size(); i++) {
            res += abs(1LL*nums[i] - m) * cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long res = LLONG_MAX;
        int n = nums.size();
        int l = nums[0], r = nums[0];
        for(int i : nums) {
            l = min(l, i);
            r = max(r, i);
        }
        while(l <= r) {
            int mid = l + (r-l) / 2;
            long long tmp1 = calcCost(nums, cost, mid);
            long long tmp2 = calcCost(nums, cost, mid + 1);

            if(tmp1 > tmp2) {
                res = tmp2;
                l = mid + 1;
            }
            else {
                res = tmp1;;
                r = mid - 1;
            }
        }
        return res;
    }
};