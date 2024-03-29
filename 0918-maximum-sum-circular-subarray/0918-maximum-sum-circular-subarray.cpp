class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, curr = 0, maxSum = 0, flag = 1, ans = INT_MIN;
        for(int i : nums) {
            if(i >= 0){
                flag = 0;
                break;
            }
            ans = max(ans, i);
        }
        
        if(flag)
            return ans; 
        
        for(int i: nums) {
            totalSum += i;
            curr += i;
            maxSum = max(maxSum, curr);
            if(curr < 0)
                curr = 0;
        }
        int minSum = INT_MAX;
        curr = 0;
        for(int i : nums) {
            curr += i;
            minSum = min(minSum, curr);
            if(curr > 0)
                curr = 0;
        }
        int ans2 = totalSum - minSum;
        return max(maxSum, ans2);
    }
};