class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int, int>> v;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ind = 0;
        int cols = mat[0].size();
        for (auto row : mat) {
            int ones = 0;
            for (; ones < cols; ones++)
                if (row[ones] == 0)
                    break;
            pq.push({ones, ind});
            ind++;
        }
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};