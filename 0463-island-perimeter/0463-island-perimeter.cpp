class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]) {
                    res += 4;
                    if(i<rows-1 and grid[i+1][j] == 1) res--;
                    if(i>0 and grid[i-1][j] == 1) res--;
                    if(j>0 and grid[i][j-1] == 1) res--;
                    if(j<cols-1 and grid[i][j+1] == 1) res--;
                }
            }
        }
        return res;
    }
};