class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        vector<int> res(2);
        int sum = 0;
        for(int i: nums) {
            if(s.find(i) != s.end()) res[0] = i;
            s.insert(i);
            sum += i;
        }
        res[1] = (n*(n+1)/2) - sum + res[0];
        return res;
    }
};