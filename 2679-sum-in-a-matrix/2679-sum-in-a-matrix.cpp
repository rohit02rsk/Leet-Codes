class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int rows = nums.size();
        int cols = nums[0].size();
        
        for(int i = 0; i < rows; i++) {
            auto &row = nums[i];
            sort(row.begin(), row.end());
        }
        
        int res = 0;
        int score;
        while(cols--) {
            score = 0;
            for(auto &row: nums) 
                score = max(score, row[cols]);
            res += score;
        }
        
        return res;
    }
};