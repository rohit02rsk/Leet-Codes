class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(auto& i : s) {
            if(s.count(i-1)) continue;
            int curr = 1;
            while(s.count(i + curr)) curr++;
            res = max(res, curr);
        }
        return res;
    }
};