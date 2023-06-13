class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;
        int res = 0;

        for(auto row : grid) 
            mp[row]++;
        for(int i=0; i<n; i++) {
            vector<int> temp;
            for(int j=0; j<n; j++) {
                temp.emplace_back(grid[j][i]);
            }
            res += mp[temp];
        }

        return res;
    }
};