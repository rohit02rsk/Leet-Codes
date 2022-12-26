class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, j = 0;
        for(i = nums.size() - 2; i >= 0; i--) {
            j++;
            if(nums[i] >= j) j = 0;
        }
        return j == 0;
    }
};