class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        if(n%2) {
            for(int i=0; i<n; i++) {
                if(i != (n-1)/2) sum += mat[i][i];
            }
            for(int i=0; i<n; i++) {
                sum += mat[i][n-1-i];
            }
        } else {
            for(int i=0; i<n; i++) {
                sum += mat[i][i];
            }
            for(int i=0; i<n; i++) {
                sum += mat[i][n-1-i];
            }
        }
        return sum;
    }
};