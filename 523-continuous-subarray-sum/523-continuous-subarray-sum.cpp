class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefSum = 0;
        unordered_map<int, int> m;
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++) {
            prefSum += nums[i];
            prefSum %= k;
            if(prefSum == 0 && i > 0) return true;
            
            if(m.find(prefSum) != m.end()) {
                if(i - m[prefSum] > 1) {
                    return true;
                }
            }
            else {
                m[prefSum] = i;
            }
        }
        
        return false;
    }
};