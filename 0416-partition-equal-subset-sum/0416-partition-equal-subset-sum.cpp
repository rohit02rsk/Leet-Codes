class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> dp;
        int t = 0;
        for(int i : nums) t += i;
        
        if(t % 2)
            return false;
        t /= 2;

        dp.insert(0);
        for(int i=0; i<nums.size(); i++) {
            unordered_set<int> temp;
            for(auto x : dp) {
                if(x + nums[i] == t)
                    return true;
                temp.insert(x + nums[i]);
                temp.insert(x);
            }
            dp = temp;
        }

        return false;
    }
};