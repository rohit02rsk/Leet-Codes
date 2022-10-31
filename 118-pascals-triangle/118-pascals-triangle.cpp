class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        
        for(int i = 1 ; i<=n ; i++) {
            vector<int> temp;
            for(int j = 1 ; j <= i ; j++) {
                if(j == 1 || j == i) temp.push_back(1);
                else {
                    temp.push_back(res[i-2][j-1] + res[i-2][j-2]);
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};