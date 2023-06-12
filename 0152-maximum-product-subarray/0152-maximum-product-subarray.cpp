class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int currMin = 1;
        int currMax = 1;
        for(int i=0; i<nums.size(); i++) {
            if(n == 0) {
                currMax = 1;
                currMin = 1;
                continue;
            }
            int temp = currMax*nums[i];
            currMax = max(currMax*nums[i], max(currMin*nums[i], nums[i]));
            currMin = min(temp, min(currMin*nums[i], nums[i]));
            res = max(res, currMax);
        }
        return res;
    }
};