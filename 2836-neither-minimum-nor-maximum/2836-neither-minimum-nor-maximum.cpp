class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
            if(nums[i] != mini and nums[i] != maxi)
                return nums[i];
        return -1;
    }
};