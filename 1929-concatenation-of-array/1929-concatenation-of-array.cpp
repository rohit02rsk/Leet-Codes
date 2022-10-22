class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = 2*(nums.size());
        vector<int> res(n);
        for(int i=0 ; i<n ; i++) 
            res[i] = nums[i%(n/2)];
        return res;
    }
};