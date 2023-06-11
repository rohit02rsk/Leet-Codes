class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int prev1 = 0;
        int prev2 = 0;
        int prev3 = 0;
        // rob 1st house, leave last house
        for(int i=0; i<nums.size()-1; i++) {
            int temp = max(nums[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        // rob last house, leave first house
        prev1 = 0;
        for(int i=1; i<nums.size(); i++) {
            int temp = max(nums[i] + prev1, prev3);
            prev1 = prev3;
            prev3 = temp;
        }
        return max(prev2, prev3);
    }
};