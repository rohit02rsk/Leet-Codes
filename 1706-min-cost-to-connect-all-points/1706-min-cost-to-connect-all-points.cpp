class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<int> vis;
        set<pair<int, int>> minHeap;
        vector<vector<int>> adj(n, vector<int>(n));
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                adj[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[j][i] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        minHeap.insert({0, 0});
        while(vis.size() < n) {
            auto [cost, curr] = *minHeap.begin();
            minHeap.erase(minHeap.begin());
            
            if(!vis.count(curr)) {
                res += cost;
                vis.insert(curr);
            }
            else continue;

            for(int i=0; i<n; i++) {
                if(!vis.count(i)) {
                    minHeap.insert({adj[i][curr], i});
                }
            }
        }
        return res;
    }
};