class Solution {
public:
    int binSearch(vector<int>& nums, int k, bool dir) {
        int l = 0, r = nums.size() - 1;
        int i = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(k > nums[m]) l = m + 1;
            else if(k < nums[m]) r = m - 1;
            else {
                i = m;
                if(dir) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binSearch(nums, target, true);
        int right = binSearch(nums, target, false);
        return {left, right};
    }
};