class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto x : rows) {
            setRows(matrix, x);
        }
        for(auto x : cols) {
            setCols(matrix, x);
        }
    }
    void setRows(vector<vector<int>>& m, int r) {
        int cols = m[0].size();
        for(int i=0; i<cols; i++) m[r][i] = 0;
    }
    void setCols(vector<vector<int>>& m, int c) {
        int rows = m.size();
        for(int i=0; i<rows; i++) m[i][c] = 0;
    }
};