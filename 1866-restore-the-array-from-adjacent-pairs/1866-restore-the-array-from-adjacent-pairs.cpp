class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        unordered_set<int> vis;
        queue<int> q;
        vector<int> res;
        int start;
        for (auto p : adjacentPairs) {
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }
        for (auto [k, v] : mp) {
            if (v.size() == 1) {
                start = k;
                break;
            }
        }
        q.push(start);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            vis.insert(x);
            for (auto i : mp[x]) 
                if (!vis.count(i))
                    q.push(i);
        }
        return res;
    }
};