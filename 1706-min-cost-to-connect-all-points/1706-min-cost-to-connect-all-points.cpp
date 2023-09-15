class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<int> vis;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int adj[n][n];
        int res = 0;

        for(int i=0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int tmp = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i][j] = tmp;
                adj[j][i] = tmp;
            }
        }

        pq.push({0, 0});
        while(vis.size() != n) {
            auto [cost, curr] = pq.top();
            pq.pop();
            
            if(vis.count(curr))
                continue;
            
            res += cost;
            vis.insert(curr);

            for(int i=0; i<n; i++)
                if(!vis.count(i))
                    pq.push({adj[curr][i], i}); 
        }

        return res;
    }
};