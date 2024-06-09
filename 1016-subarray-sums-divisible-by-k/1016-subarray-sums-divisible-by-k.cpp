class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pre_sum = 0, res = 0;
        vector<int> arr(k);
        arr[0] = 1;
        for (int i : nums) {
            pre_sum = (pre_sum + i) % k;
            if (pre_sum < 0) pre_sum += k;
            res += arr[pre_sum];
            arr[pre_sum]++;
        }
        return res;
    }
};