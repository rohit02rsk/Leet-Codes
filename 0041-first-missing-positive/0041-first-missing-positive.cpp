class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<long long int> s(nums.begin(), nums.end());
        long long int n = *max_element(nums.begin(), nums.end());
        for(long long int i=1; i<=n+1; i++) {
            if(!s.count(i)) return i;
        }
        return 1;
    }
};