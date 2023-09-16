class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        dis[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [d, coord] = pq.top();
            auto [x, y] = coord;
            pq.pop();

            if (x == m-1 and y == n-1)
                return d;
            
            for (int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (newX < 0 or newY < 0 or newX >= m or newY >= n)
                    continue;

                int newD = max(d, abs(heights[newX][newY] - heights[x][y]));
                if (newD < dis[newX][newY]) {
                    dis[newX][newY] = newD;
                    pq.push({newD, {newX, newY}});
                }
            }
        }

        return -1;
    }
};