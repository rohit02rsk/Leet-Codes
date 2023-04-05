class Solution {
public:
    bool isValid(int x, vector<int> nums) {
        long long int prefSum = 0;
        for(int i=0; i<nums.size(); i++) {
            prefSum += nums[i];
            if(prefSum > (i+1)*(long long)x) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while(l < r) {
            int mid = (l+r)/2;
            if(isValid(mid, nums)) {
                r = mid;
            } else {
                l = mid+1;
            } 
        }
        return l;
    }
};