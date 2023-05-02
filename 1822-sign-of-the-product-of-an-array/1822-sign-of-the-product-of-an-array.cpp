class Solution {
public:
    int arraySign(vector<int>& nums) {
        int s = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) s++;
        }
        return s%2 ? -1 : 1;
    }
};