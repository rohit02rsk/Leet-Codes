class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        set<pair<int, int>> vis;
        
        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()) {
            auto [h, coords] = pq.top();
            int i = coords.first;
            int j = coords.second;
            pq.pop();
            if(i == n-1 and j == n-1)
                return h;
            
            for(auto [dx, dy] : dir) {
                int x = i + dx;
                int y = j + dy;
                if(x >= 0 and y >= 0 and x < n and y < n and !vis.count({x, y})) {
                    pq.push({max(h, grid[x][y]), {x, y}});
                    vis.insert({x, y});
                }
            }
        }

        return -1;
    }
};