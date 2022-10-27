class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> vec_a;
        vector<pair<int, int>> vec_b;
        int res = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(img1[i][j] == 1) {
                    vec_a.push_back({i, j});
                }
                if(img2[i][j] == 1) {
                    vec_b.push_back({i, j});
                }
            }
        }
        
        map<pair<int, int> ,int> m;
        for(auto [i1,j1]: vec_a) {
            for(auto [i2,j2]: vec_b) {
                m[{i1-i2, j1-j2}]++;
                res = max(res, m[{i1-i2,j1-j2}]);
            }
        }
        
        return res;
    }
};