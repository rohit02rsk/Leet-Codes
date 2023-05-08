class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_ele = *max_element(nums.begin(), nums.end());
        return ((max_ele+k-1)*(max_ele+k)/2) - ((max_ele)*(max_ele+1)/2) + max_ele;
    }
};