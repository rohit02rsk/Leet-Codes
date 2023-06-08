class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int j = cols-1; j>=0; j--) {
            for(int i=rows-1; i>=0; i--) {
                if(grid[i][j] < 0)
                    res++;
                else break;
            }
        }
        return res;
    }
};