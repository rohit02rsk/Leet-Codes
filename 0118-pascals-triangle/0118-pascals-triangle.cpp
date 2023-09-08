class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=1; i <= numRows; i++) {
            vector<int> curr(i);
            curr[0] = 1; // first element is 0
            curr[i-1] = 1; // last element is 0
            
            int j = 1;
            while (i > 2 and j < i-1) {
                curr[j] = res[i-2][j] + res[i-2][j-1];
                j++;
            }
            res.emplace_back(curr);
        }
        return res;
    }
};