class Solution {
public:
    set<vector<int>> s;
    void help(vector<int>& nums, vector<int>& curr, vector<vector<int>>& res, int start) {
        if(!s.count(curr)) {
            res.push_back(curr);
            s.insert(curr);
        }
        for(int i=start; i<nums.size(); i++) {
            curr.emplace_back(nums[i]);
            help(nums, curr, res, i+1);    
            curr.pop_back();
        }
    }   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        help(nums, curr, res, 0);
        return res;
    }
};